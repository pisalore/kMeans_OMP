//
// Created by lorenzo on 27/12/19.
//

#ifndef KMEANS_OMP_UTILITIES_H
#define KMEANS_OMP_UTILITIES_H

#include "Point.h"
#include "Cluster.h"
#include <vector>

using namespace std;


std::vector<Point> initializePointsFromFile(string filename);
std::vector<Cluster> initializeClusters(int number_of_cluster, vector<Point> &points);
double euclideianDistance(Point point, Cluster cluster);
void calculateAllDistances(vector<Point> &points, vector<Cluster> &clusters);
bool findNewCentroids(vector<Cluster> &clusters);
void calculateAllDistancesParallel(vector<Point> &points, vector<Cluster> &clusters);
bool findNewCentroidsParallel(vector<Cluster> &clusters);
void plotClusters(vector<Point> &points);
void plotCentroids(vector<Cluster> &clusters);



#endif //KMEANS_OMP_UTILITIES_H
