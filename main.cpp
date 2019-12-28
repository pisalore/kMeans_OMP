#include <iostream>
// OpenMP header
#include <omp.h>

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include <math.h>
#include "csvio.h"
#include "Utilities.h"

#include <algorithm> // for copy() and assign()
#include <iterator> // for back_inserter



int main(int argc, char* argv[]){
    const int clusters_number = 3;
    const double max_random_range = 20;
    std::string filename = "../datasets/dataset1000.csv";

    //building points array to be clustered and random clusters
    vector<Point> points = initializePointsFromFile(filename);
    vector<Cluster> clusters = initializeClusters(clusters_number, max_random_range);



}
