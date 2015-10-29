# Finding-k-in-kmeans-clustering
Implementation of distortion function calculation and comparison for different values of k to determine ideal k (number of clusters) in k-means clustering:

Index:
1. Description:
2. Contents:
3. Requirments:
4. Execute Instructions:
5. Authors:

#############################################################################################################################
1. Description:

This is my quick and naive implementation of method discussed in the following paper by Pham et.al: http://www.ee.columbia.edu/~dpwe/papers/PhamDN05-kmeans.pdf 
  a.	The goal of a clustering algorithm is to identify regions in which the data points are concentrated. It is also     important to analyze the internal distribution of each cluster as well as its relation to other clusters in the data set. The distortion of a cluster is a measure of the distance between points in a cluster and its centroid: <br>
  <img src = "https://s0.wp.com/latex.php?latex=%5Cdisplaystyle+I_j+%3D+%5Csum_%7B%5Cmathrm%7Bx%7D_i+%5Cin+C_j%7D+%7C%7C%5Cmathrm%7Bx%7D_i+-+%5Cmu_j+%7C%7C%5E2&bg=ffffff&fg=000000&s=0" align="middle"><br>
  b.	The global impact of all clusters’ distortions is given by the quantity
  c.	The authors Pham et al. proceed to discuss further constrains that the sought-after function f(K) should verify for it to be informative to the problem of selection of K. They finally arrive at the following definition: Nd is the number of dimensions (attributes) of the data set and alpha is a weight factor. 
  d.	With this definition, f(K) is the ratio of the real distortion to the estimated distortion and decreases when there are areas of concentration in the data distribution. Values of K that yield small f(K) can be regarded as giving well-deﬁned clusters.
  
2. Contents:
  a. SRC
    1. main.cpp #function calls
    2. k_for_kmeans.h  #libraries included, variables and functions initialized
    3. k_for_kmeans.cpp #functions defined
    4. CMakeLists.txt #self-explanatory
    5. Makefile
  b. Input
    1. Lena.png
  c. Output
    1. results.txt 
  
3. Requirements:
Since, I am working with images, I am using OpenCV 2.4.9. But this can be avoided by linking appropriate libraries(refer to k_for_kmeans.h) with the G++ compiler as well.

4. Execute Instructions:
CMAkeLists.txt highlights mentions the order to link the files. 
Output is generated to the results.txt file in Output folder with the ideal k and its corresponding distortion

5. Authors:
Chinmaya Joshi
