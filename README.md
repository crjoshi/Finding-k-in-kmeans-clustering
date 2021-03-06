# Finding-k-in-kmeans-clustering
Implementation of distortion function calculation and comparison for different values of k to determine ideal k (number of clusters) in k-means clustering:

Index:<br>
<ol>
<li>Description</li>
<li> Contents</li>
<li> Requirments</li>
<li>Execute Instructions</li>
<li>Authors</li>
</ol>
#############################################################################################################################
<ol>
<li><strong>Description:</strong>

This is my quick and naive implementation of method discussed in the following paper by Pham et.al: http://www.ee.columbia.edu/~dpwe/papers/PhamDN05-kmeans.pdf
<ul>
<li>The goal of a clustering algorithm is to identify regions in which the data points are concentrated. It is also     important to analyze the internal distribution of each cluster as well as its relation to other clusters in the data set. The distortion of a cluster is a measure of the distance between points in a cluster and its centroid: <br>
  <p align="center"><img align="middle" src = "https://s0.wp.com/latex.php?latex=%5Cdisplaystyle+I_j+%3D+%5Csum_%7B%5Cmathrm%7Bx%7D_i+%5Cin+C_j%7D+%7C%7C%5Cmathrm%7Bx%7D_i+-+%5Cmu_j+%7C%7C%5E2&bg=ffffff&fg=000000&s=0"></p><br>
</li>
<li>The global impact of all clusters’ distortions is given by the quantity:<br>
  <p align="center"><img src="https://s0.wp.com/latex.php?latex=%5Cdisplaystyle+S_k+%3D+%5Csum_%7Bj%3D1%7D%5EK+I_j&bg=ffffff&fg=000000&s=0" align="middle"></p>
</li>
<li>The authors Pham et al. proceed to discuss further constrains that the sought-after function f(K) should verify for it to be informative to the problem of selection of K. They finally arrive at the following definition: Nd is the number of dimensions (attributes) of the data set and alpha is a weight factor. <br>
  <p align="center"><img src="https://datasciencelab.files.wordpress.com/2014/01/fk.png?w=359&h=192" align="middle"><br></p>
</li>
<li>With this definition, f(K) is the ratio of the real distortion to the estimated distortion and decreases when there are areas of concentration in the data distribution. Values of K that yield small f(K) can be regarded as giving well-deﬁned clusters.
</li>
</ul>
</li>
<br>
<li> <strong>Contents:</strong>
  <ul>
  <li>SRC:
    <ol>
    <li> main.cpp #function calls</li>
    <li> k_for_kmeans.h  #libraries included, variables and functions initialized</li>
    <li> k_for_kmeans.cpp #functions defined</li>
    <li> CMakeLists.txt #self-explanatory</li>
    <li> Makefile </li>
    </ol>
  </li>
  <li>Input:
    <ol>
    <li>Lena.png</li>
    </ol>
  </li>
  <li>Output:
    <ol>
    <li>results.txt</li>
    </ol>
  </li>
  </ul>
</li>

<li><strong>Requirements:</strong>
Since, I am working with images, I am using OpenCV 2.4.9. But this can be avoided by linking appropriate libraries(refer to k_for_kmeans.h) with the G++ compiler as well.
</li>

<li><strong>Execute Instructions:</strong>
CMAkeLists.txt highlights mentions the order to link the files. 
Output is generated to the results.txt file in Output folder with the ideal k and its corresponding distortion
</li>

<li><strong>Authors:</strong>
Chinmaya Joshi
</li>
