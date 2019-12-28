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
std::vector<Cluster> initializeClusters(int number_of_cluster, int max_range);


#endif //KMEANS_OMP_UTILITIES_H