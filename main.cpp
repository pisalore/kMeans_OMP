//
// Created by lorenzo on 27/12/19.
//

#include <iostream>
#include <omp.h>

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include <math.h>
#include "csvio.h"
#include "Utilities.h"


int main(int argc, char *argv[]) {
    const int clusters_number = 3;
    const double max_random_range = 20;
    std::string filename = "../datasets/dataset1000.csv";

    //building points array to be clustered and random clusters
    vector<Point> points = initializePointsFromFile(filename);
    vector<Cluster> clusters = initializeClusters(clusters_number, max_random_range);
    for (int i = 1; i < 3; i++) {
        calculateAllDistances(points, clusters);
        findNewCentroids(clusters);
    }

    int i = 0;
}
