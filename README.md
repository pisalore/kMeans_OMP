# K-Means algorithm with OpenMP
## A simple k-Means algorithm implementation with C++ and OMP.

K-Means is a widely used clustering procedure. This algorithm is lightweight (O(n)): given a points dataset each point is processed at each iteration, calculating its distance with the k **centroids** which representes the cluster at that time; then, an *update procedure* find new centroids calculating **means** and verifying if convergence has been reached. K-Means could be summed up like this:
1. Initialization phase (where first k cluster are chosen according to some criterion);
2. Computing distances phase (where each point is assigned to its nearest centroid cluster); 
3. Updating phase (new centroids are computed and convergence is verified).

This repo belongs to the final Master Degree Parallel Computing Project: here there is the sequential and OMP versions of k-Means algorithm; following this link is possibile to find the [CUDA k-Means](https://github.com/pisalore/kMeans_CUDA).
The main idea is to compare k-Means with Means SHift algorithm also: [here](https://github.com/pisalore/kMeans_CUDA/blob/master/PC_kMeans_final.pdf) the related paper.

## Getting Started

Please, consider to download [CLion](https://www.jetbrains.com/clion/download/download-thanks.html): with this IDE you will have all the necessary to launch the application, builded with **CMake**.
In *dataset* folder, 2D points dataset are provided. With the *Generator* script it's possibile to create your own dataset, changing points dimension and dataset size.
