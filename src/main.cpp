#include "k_for_kmeans.h"

int main (int argc, char** argv) {
	
	if (argc < 1 || argc > 2){
		std:: cout<<"Usage: "<<argv[0]<<"Image Path\n";
		return -1;
	}
	
	string filename;
	argc < 2 ? filename = "../input/lena.png"
		 : filename = argv[1];


	k_for_kmeans scan;
	scan.Input_Generator(filename);
	scan.Runner();
	scan.Distortion_Calculator();
	scan.Output_Generator();

	return 0;
}
