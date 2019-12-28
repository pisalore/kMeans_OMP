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
    const double max_random_range = 20;
    const double max_iterations = 100;
    bool isNotConvergence = true;
    int numIterations = 0;

    std::string filename = "../datasets/dataset1000.csv";

    //building points array to be clustered and random clusters
    vector<Point> points = initializePointsFromFile(filename);
    vector<Cluster> clusters = initializeClusters(clusters_number, max_random_range);
    while (isNotConvergence && numIterations < max_iterations) {
        calculateAllDistances(points, clusters);
        isNotConvergence = findNewCentroids(clusters);
    }
    for (int i = 0; i < clusters.size(); i++) {
        std::cout << "Cluster " << i << ": " << "(" << clusters[i].get_x_cluster_coordinate() << ", "
                  << clusters[i].get_y_cluster_coordinate() << ")" << std::endl;
    }

}
