//
// Created by lorenzo on 27/12/19.
//
#include <iostream>
#include <cstdlib>

#include "Utilities.h"
#include "Point.h"
#include "Cluster.h"
#include "csvio.h"

std::vector<Point> initializePointsFromFile(string filename){
    const int point_dim = 2;
    //allocating data structures
    std::vector<float> inputData;
    float * InputPoints_ptr;
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

    for( int i = 0; i < input_dimension; i ++){
        int it = i * point_dim;
        Point* point = new Point(inputData[it], inputData[it + 1]);
        ptr[i] = *point;

    }
    return points;
}

std::vector<Cluster> initializeClusters(int number_of_cluster, int max_range){
    vector<Cluster> clusters(number_of_cluster);
    Cluster* ptr = &clusters[0];

    for(int i = 0; i < number_of_cluster; i ++){
        Cluster *cluster = new Cluster(rand() % (int) max_range, rand() % (int) max_range);
        ptr[i] = *cluster;
    }
    return clusters;
}