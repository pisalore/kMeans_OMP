//
// Created by lorenzo on 27/12/19.
//

#include <iostream>
#include <omp.h>
#include <iostream>
#include "csvio.h"
#include "Utilities.h"


int main(int argc, char *argv[]) {
    const int clusters_number = 3;
    const int max_random_range = 20;
    const double max_iterations = 100;
    bool isNotConvergence = true;
    int numIterations = 0;

    std::string filename = "../datasets/dataset1000.csv";

    //building points array to be clustered and random clusters
    vector<Point> points = initializePointsFromFile(filename);
    vector<Cluster> clusters = initializeClusters(clusters_number, points);
    std::cout << "K Means Computation started. "<< std::endl;
    double startTime = omp_get_wtime();
    while (isNotConvergence && numIterations < max_iterations) {
        numIterations ++;
        calculateAllDistances(points, clusters);
        isNotConvergence = findNewCentroids(clusters);
    }
    double endTime = omp_get_wtime();
    std::cout << "K Means ended in " << endTime - startTime << "s" << std::endl;
    std::cout<< "Clusters found:" << std::endl;
    for (int i = 0; i < clusters.size(); i++) {
        std::cout << "Cluster " << i << ": " << "(" << clusters[i].get_x_cluster_coordinate() << ", "
                  << clusters[i].get_y_cluster_coordinate() << ")" << std::endl;
    }
    std::cout << "Plotting results... "<< std::endl;
    plotClusters(points);
    plotCentroids(clusters);
}
