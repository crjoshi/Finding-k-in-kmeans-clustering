#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;
using namespace cv;

class k_for_kmeans {
	
	private:
		Mat input;				//input image in RGB (as is)
		Mat data;				//input image converted to grayscale
		Mat fsamples;				//one dimenstional vector to hold entire data
		vector<float> vector_of_compactness;

		//initializing variables for kmeans
		Mat labels;				//holds cluster indices for every pixel
		Mat centers;				//holds final centroids of the kmeans clustering
		int attempts;				//number of iterations/attempts for determining the centroid
		float compactness;			// Sum of Squared Error for entire dataset i.e. Sum(|x_i - centroid_i|^2) for i =1 to k.

		
		//initializing variables for distortion function
		vector<float> alpha_vector;  		// to hold all wights corresponding to f(k) values
		vector<float> f_k_vector; 		//to hold all f(k) (distortion) values
		int Nd; 				//no. of dimenstions: 1 in this case since kmeans is performed on intensity values
		float alpha; 				//respective weight
		float f_k;				//respective distortion
		pair<int, float> tmp_pair;
		vector<pair<int, float> > vector_for_k; //to hold pair of k and corresponding f(k) values.

	public:
		void Input_Generator(string filename);	//generates fsamples matrix
		void Runner();				//runs kmeans in in a loop over the same dataset
		void Distortion_Calculator();		//calculated distortion for each k that was run in Runner()
		void Output_Generator();		//generates a text file in the folder output to display: 1. desired k, & 2. verification of the same

};
