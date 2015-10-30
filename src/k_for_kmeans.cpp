#include "k_for_kmeans.h"


void k_for_kmeans::Input_Generator(string filename){
	input = imread(filename,1);
	
	data = Mat::zeros(input.rows, input.cols, CV_32S);
	for(int r = 0; r < input.rows; ++r){
		for(int c = 0; c < input.cols; ++c) {
			data.at<int>(r,c) = (int(input.at<Vec3b>(r,c)[0])*0.1140) 
					     + (int(input.at<Vec3b>(r,c)[1])*0.5970) 
					     + (int(input.at<Vec3b>(r,c)[2])*0.2889);
		}
	}

	//vectorized the data matrix and typecasted to float
	fsamples = Mat::zeros(input.rows*input.cols,1,CV_32F);
	for(int r = 0; r < input.rows; ++r){
		for(int c = 0; c < input.cols; ++c) {
			fsamples.at<float>(c+r*input.cols) = float(data.at<int>(r,c));
		}
	}
}



void k_for_kmeans::Runner() {
	attempts = 10;
	vector_of_compactness.clear();
	for(int k = 2; k <=20; ++k){
	compactness = kmeans(fsamples, k, labels, TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,10,3.0), attempts, KMEANS_PP_CENTERS,centers);
	vector_of_compactness.push_back(compactness);
	}
	cout<<vector_of_compactness.size()<<endl;
	
}


void k_for_kmeans::Distortion_Calculator(){	
	f_k_vector.clear();
	alpha_vector.clear();
	Nd = 1;
	vector_for_k.clear();
	for (int k = 2; k<= 20; ++k) {
		if (k == 2){
			alpha = 1-3/(4*Nd);
			f_k = 1; // since S1 = 0 (by definition) 
			alpha_vector.push_back(alpha);
	        f_k_vector.push_back(f_k);
		}
		else {
			alpha = alpha_vector[k-3] + (1 - alpha_vector[k-3])/6;
			if (vector_of_compactness[k-3]==0){
				f_k = 1; // if Sk-1 == 0, then f(k) = 1 (by definition)
			}
			else {
				f_k = vector_of_compactness[k-2]/(alpha*(vector_of_compactness[k-3]));
			}
			alpha_vector.push_back(alpha);
			f_k_vector.push_back(f_k);
		}
		
		tmp_pair.first = k;
		tmp_pair.second = f_k;
		vector_for_k.push_back(tmp_pair);
	}
	//lambda function //make sure to include c++11 flag
	std::sort(vector_for_k.begin(), vector_for_k.end(),[](const pair<int, float> & a, const pair<int, float> & b){return a.second < b.second;});
} 		

void k_for_kmeans::Output_Generator(){
	
	ofstream output;
	output.open("../output/result.txt");
	output<<"value of  optimum k is"<<vector_for_k[0].first<<" f_k value is "<<vector_for_k[0].second<<endl;
	
	output<<"****VERIFICATION_RUN****"<<endl;
	for (int i = 0; i < vector_for_k.size(); ++i){
		output<<"f_k = "<<vector_for_k[i].second<<" k = "<<vector_for_k[i].first<<endl;
	}
	output<<"****VERIFICATION_RUN_ENDS****"<<endl;
	output.close();
}
