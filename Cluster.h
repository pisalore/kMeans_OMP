//
// Created by lorenzo on 27/12/19.
//

#ifndef KMEANS_OMP_CLUSTER_H
#define KMEANS_OMP_CLUSTER_H

class Cluster {
private :
    double x_cluster_coordinate;
    double y_cluster_coordinate;
    double x_cluster_accumulator;
    double y_cluster_accumulator;
    int size;

public:
    Cluster(double x, double y){
        this->x_cluster_coordinate = x;
        this->y_cluster_coordinate = y;
        this->x_cluster_accumulator = 0;
        this->y_cluster_accumulator = 0;
    }

    Cluster(){
        this->x_cluster_coordinate = 0;
        this->y_cluster_coordinate = 0;
        this->x_cluster_accumulator = 0;
        this->y_cluster_accumulator = 0;
    }
    //Getters
    double get_x_cluster_coordinate(){
        return this->x_cluster_coordinate;
    }

    double get_y_cluster_coordinate(){
        return this->y_cluster_coordinate;
    }

    double get_size(){
        return this->size;
    }

    //Setters
    void set_x_cluster_coordinate(double x){
        this->x_cluster_coordinate = x;
    }

    void set_y_cluster_coordinate(double y){
        this->y_cluster_coordinate = y;
    }

    void accumulateClusterPoints(Point point) {
        this->x_cluster_accumulator += point.get_x_coordinate();
        this->y_cluster_accumulator += point.get_y_coordinate();
    }
};

#endif //KMEANS_OMP_CLUSTER_H
