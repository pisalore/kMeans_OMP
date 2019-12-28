//
// Created by lorenzo on 26/12/19.
//

#ifndef KMEANS_OMP_CSVIO_H
#define KMEANS_OMP_CSVIO_H

#include <vector>
#include <string>

void write2VecTo(std::string filename, std::string delimiter, std::vector<float>& vec);
void read2VecFrom(std::string filename, std::string delimiter, std::vector<float>& dest);

#endif //KMEANS_OMP_CSVIO_H
