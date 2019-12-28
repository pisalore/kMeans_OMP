//
// Created by lorenzo on 27/12/19.
//

#ifndef KMEANS_OMP_POINT_H
#define KMEANS_OMP_POINT_H

class Point {

private :
    double x;
    double y;
    int cluster_id;

public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;

    }


    Point(){
        x = 0;
        y = 0;
        cluster_id = 0;
    }
    //Getters
    double get_x_coordinate() {
        return this->x;
    }

    double get_y_coordinate(){
        return this->y;
    }

    int get_cluster_id(){
        return this->cluster_id;
    }
    //Setters
    void set_x_coordinate(double x_coord){
        this->x = x_coord;
    }

    void set_y_coordinate(double y_coord){
        this->y = y_coord;
    }

    void set_clster_id(int id){
        this->cluster_id = id;
    }

};

#endif //KMEANS_OMP_POINT_H
