//
// Created by lorenzo on 27/12/19.
//
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <omp.h>
#include "Utilities.h"
#include "Point.h"
#include "Cluster.h"
#include "csvio.h"

std::vector<Point> initializePointsFromFile(string filename) {
    const int point_dim = 2;
    //allocating data structures
    std::vector<float> inputData;
    float *InputPoints_ptr;
    std::string delimiter = ";";
    //read data from file
    read2VecFrom(filename, delimiter, inputData);
    int input_dimension = inputData.size() / 2;
    InputPoints_ptr = new float[inputData.size()];
    for (int i = 0; i < inputData.size(); i++) {
        InputPoints_ptr[i] = inputData[i];
    }
    vector<Point> points(input_dimension);
    Point *ptr = &points[0];

    for (int i = 0; i < input_dimension; i++) {
        int it = i * point_dim;
        Point *point = new Point(inputData[it], inputData[it + 1]);
        ptr[i] = *point;

    }
    return points;
}

std::vector<Cluster> initializeClusters(int number_of_cluster, vector<Point> &points) {
    vector<Cluster> clusters(number_of_cluster);
    Cluster *ptr = &clusters[0];
    for (int i = 0; i < number_of_cluster; i++) {
        int r = rand() % points.size() / 10;
        Point &point = points[r];
        double x = point.get_x_coordinate();
        double y = point.get_y_coordinate();
        Cluster *cluster = new Cluster(x, y);
        ptr[i] = *cluster;
    }
    return clusters;
}

void calculateAllDistances(vector<Point> &points, vector<Cluster> &clusters) {
    int pointsSize = points.size();
    int clustersSize = clusters.size();
    double minDistance = 0;
    int clusterIndex = 0;
    for (int i = 0; i < pointsSize; i++) {
        Point &point = points[i];
        minDistance = euclideianDistance(point, clusters[0]);
        for (int j = 0; j < clustersSize; j++) {
            Cluster &cluster = clusters[j];
            double distance = euclideianDistance(point, cluster);
            if (distance < minDistance) {
                minDistance = distance;
                clusterIndex = j;
            }
        }
        points[i].set_cluster_id(clusterIndex);
        clusters[clusterIndex].accumulateClusterPoints(points[i]);
    }
}

void calculateAllDistancesParallel(vector<Point> &points, vector<Cluster> &clusters) {
    int pointsSize = points.size();
    int clustersSize = clusters.size();
    double minDistance;
    int clusterIndex;
#pragma omp parallel default(shared) private(minDistance, clusterIndex) firstprivate(pointsSize, clustersSize)
#pragma omp for schedule(static)
    for (int i = 0; i < pointsSize; i++) {
        Point &point = points[i];
        minDistance = euclideianDistance(point, clusters[0]);
        clusterIndex = 0;
        for (int j = 1; j < clustersSize; j++) {
            Cluster &cluster = clusters[j];
            double distance = euclideianDistance(point, cluster);
#pragma omp critical
            if (distance < minDistance) {
                minDistance = distance;
                clusterIndex = j;
            }
        }
        points[i].set_cluster_id(clusterIndex);
        clusters[clusterIndex].accumulateClusterPoints(points[i]);
    }
}


bool findNewCentroids(vector<Cluster> &clusters) {
    bool isConvergence = false;
    for (int i = 0; i < clusters.size(); i++) {
        isConvergence = clusters[i].updateClusterCentroid();
        clusters[i].resetClusterAccumulator();
    }

    return isConvergence;
}

bool findNewCentroidsParallel(vector<Cluster> &clusters) {
    bool isConvergence = false;
#pragma omp parallel for lastprivate(isConvergence)
    for (int i = 0; i < clusters.size(); i++) {
        isConvergence = clusters[i].updateClusterCentroid();
        clusters[i].resetClusterAccumulator();
    }

    return isConvergence;
}

double euclideianDistance(Point point, Cluster cluster) {
    double distance = sqrt(pow(point.get_x_coordinate() - cluster.get_x_cluster_coordinate(), 2)
                           + pow(point.get_y_coordinate() - cluster.get_y_cluster_coordinate(), 2));

    return distance;
}


void plotClusters(vector<Point> &points) {
    ofstream outfile("data.txt");
    for (int i = 0; i < points.size(); i++) {
        Point point = points[i];
        outfile << point.get_x_coordinate() << " " << point.get_y_coordinate() << " " << point.get_cluster_id()
                << std::endl;
    }
    outfile.close();
    system("gnuplot -p -e \"plot 'data.txt' using 1:2:3 with points palette notitle\"");
    remove("data.txt");
}

void plotCentroids(vector<Cluster> &clusters) {
    ofstream outfile("centroids.txt");
    for (int i = 0; i < clusters.size(); i++) {
        Cluster cluster = clusters[i];
        outfile << cluster.get_x_cluster_coordinate() << " "
                << cluster.get_y_cluster_coordinate() << std::endl;
    }
    outfile.close();
    system("gnuplot -p -e \"plot 'centroids.txt' notitle\"");
    remove("centroids.txt");
}

