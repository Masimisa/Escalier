// Version XOR
// Principe : Faire un premier threshold a 50%, un second a 46%
// Faire un XOR sur le second si == 255 sinon 0
// Premier - Second, c'est-à-dire que si second[][] == 0, alors premier[][] = 255

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <stdint.h>

using namespace std;
using namespace cv;


int findBestThreshold(Mat img, float n){
	Mat th;
	float nbNoir, nbBlanc, ratio;
	for(int i = 0; i < 256; i++){
		threshold(img, th, i, 255, THRESH_BINARY );
		nbNoir = countNonZero(th);
		nbBlanc = (th.rows * th.cols) - countNonZero(th);
		ratio = nbBlanc/nbNoir;
		
		if (ratio > n)
			return i;
	}
}

void emulateNumpy(Mat &img, vector<vector<int>> &numpy){
	int nbLignes = img.rows;
	int nbColonnes = img.cols;
	int nbTotalElement = nbLignes * nbColonnes;

	int positionX = 0;
	int positionY = 0;
	int pixelCourant = 0;

	for (int i = 0; i < nbTotalElement; i++){
		positionX = i / nbColonnes;
		positionY = i % nbColonnes;
		pixelCourant = int(img.at<uint8_t>(positionX, positionY));
		numpy[i / nbColonnes].push_back(pixelCourant);
	}
}

void convertNumpy2Mat(Mat &img, vector<vector<int>> &numpy){
	int nbLignes = img.rows;
	int nbColonnes = img.cols;
	int positionX = 0;
	int positionY = 0;

	int nbTotalElement = nbLignes * nbColonnes;
	for (int i = 0; i < nbTotalElement; i++)
	{
		positionX = i / nbColonnes;
		positionY = i % nbColonnes;
		img.at<uint8_t>(positionX, positionY) = numpy[positionX][positionY];
	}
}

void functionXor(vector<vector<int>> &numpyXor, vector<vector<int>> &numpy){
	for (int i = 0; i < numpy.size(); i++){
		for (int j = 0; j < numpy[i].size(); j++){
			if(numpy[i][j] ==  numpyXor[i][j]){
				numpyXor[i][j] = 255;
			}else{
				numpyXor[i][j] = 0;
			}
		}
	}
}

void functionLess(vector<vector<int>> &numpyXor, vector<vector<int>> &numpy){
	for (int i = 0; i < numpy.size(); i++){
		for (int j = 0; j < numpy[i].size(); j++){
			if(numpyXor[i][j] == 0)
				numpy[i][j] = 255;
		}
	}
}

// On compte par rapport au nombre de ligne
int main(){

	Mat img, th, xor_;

	string pathImg = "../../data/images/escalier.jpg";
	img = imread(pathImg, 0);
	
	threshold(img, th, 0, 255, THRESH_BINARY  | THRESH_OTSU);
	threshold(th, xor_, 0, 255, THRESH_BINARY | THRESH_OTSU);

	medianBlur(th, th, 5);

	vector<vector<int>> numpy(th.rows);
	vector<vector<int>> numpyXor(xor_.rows);

	emulateNumpy(th, numpy);
	emulateNumpy(xor_, numpyXor);

	// functionXor(numpyXor, numpy);
	// functionLess(numpyXor, numpy);

	// convertNumpy2Mat(th, numpy);
	// convertNumpy2Mat(xor_, numpyXor);
	
	imshow("Display Window", img);
	imshow("Threshold 50% Window", th);
	imshow("Threshold XOR Window", xor_);

	waitKey(0);
	destroyAllWindows();
	return 0;
}
