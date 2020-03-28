#include <iostream>
#include <cmath>
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

	for (int i = 0; i < nbTotalElement; i++)
	{
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

/*
void preprocessing_(vector<vector<int>> &numpy){
	for (int i = 0; i < numpy.size(); i++){
		for (int j = 0; j < numpy[i].size(); j++){
			if(numpy[i][j] == 255 ){


				if(i+1 > numpy.size() || j-1 < 0 || j+1 > numpy[i].size()){
					continue;
				}else{
					//if(numpy[i][j+1] == 255 && (numpy[i+1][j-1] == 255 || numpy[i+1][j+1] == 255)){
					//	numpy[i][j] = 0;
					//	numpy[i+1][j] = 255;
					//}
					if(numpy[i][j] == 0  && numpy[i][j+1] == 255 && numpy[i+1][j] == 255){
						numpy[i][j] = 255;
						//numpy[i+1][j] = 0;
					}
				}

			}
		}
	}
}
*/

void preprocessing(vector<vector<int>> &black, vector<vector<int>> &numpy){
	int nbMarche = 0;
	int x, y, width, height; // Les coordonnées du rectangle

	bool first = false; // Premiere fois qu'on rencontre un pixel blanc
	int nbBlanc = 0; // Nombre de pixel blanc rencontrer dans une ligne

	vector<int> pixelX;
	vector<int> pixelY;

	vector<int> yoloX;
	vector<int> yoloY;

	int fx=0, fy=0;
	vector<int> finX;
	vector<int> finY;

	int x1, y1, x2, y2;

	for (int i = 0; i < numpy.size(); i++){
		finX.push_back(fx);
		finY.push_back(fy);
		first = false;
		nbBlanc = 0;
		for (int j = 0; j < numpy[i].size(); j++){

			if(numpy[i][j] == 255 && !first){
				first = true;
				yoloX.push_back(j);
				yoloY.push_back(i);
			
			}
			
			if(numpy[i][j] == 255){
				fx = i;
				fy = j;
			}

			// Essage de tracer des rectangles
			/*
			if(!first && (j == numpy[i].size() - 1) && yoloX.size() > 0){
				// circle(img, Point(yoloX[i], yoloY[i]), 2, Scalar(0, 0, 255), -1);

				x1 = *min_element(yoloX.begin(), yoloX.end());
				y1 = *min_element(yoloY.begin(), yoloY.end());
				x2 = *min_element(finX.begin(), finX.end());
				y2 = *min_element(finY.begin(), finY.end());
				
				//circle(img, Point(x1, y1), 2, Scalar(0, 255, 0), -1);
				//circle(img, Point(y2, x2), 2, Scalar(0, 255, 0), -1);

				rectangle(img, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 5);

				yoloX.clear();
				yoloY.clear();
				finX.clear();
				finY.clear();

			}
			*/
		}
	}
	
	// Preprocessing : Suppression des points inutile
	for(int i = 0; i < yoloX.size(); i++){
		if(i == (yoloX.size() - 1)) continue;
		if(abs(yoloX[i] - yoloX[i+1]) > 50){
			yoloX.erase(yoloX.begin()+i+1);
			yoloY.erase(yoloY.begin()+i+1);
			i=0;
		} 
	}
	

	for(int i = 0; i < yoloX.size(); i++){
		//circle(img, Point(yoloX[i], yoloY[i]), 2, Scalar(0, 0, 255), -1);
		int a = yoloX[i];
		int b = yoloY[i];
		black[b][a] = 255;
	}

	for(int i = 0; i < finX.size(); i++){

		int a = finY[i];
		int b = finX[i];

		black[b][a] = 255;
		
		// circle(img, Point(finY[i], finX[i]), 2, Scalar(255, 0, 0), -1);
		//black[finY[i]][finX[i]] = 255;
	}

}

void drawRectangle(Mat &img, vector<vector<int>> &numpy){

	bool first = true;
	int x1, y1, x2, y2;
	int nbBlanc = 0;

	for (int i = 1; i < numpy.size(); i++){
		nbBlanc = 0;
		for (int j = 0; j < numpy[i].size(); j++){

			if(numpy[i][j] == 255 && first){
				x1 = i; y1 = j; 
				first = false;
				nbBlanc++;
			}

			if(numpy[i][j] == 255){
				x2 = i; y2 = j;
				nbBlanc++;
			}

			if(j == numpy[i].size()-1 && nbBlanc == 0) {
				//rectangle(img, Point(x1, y1), Point(x2, y2), Scalar(0, 0, 0), -1);
				cout << x1 << "-" << y1 << endl;
				cout << x2 << "-" << y2 << endl;
				cout << "---" << endl;
				rectangle(img, Rect(y1, x1, y2-y1, x2-x1), Scalar(0, 0, 0), -1);
				//rectangle(img, Rect(x1, y1, x2-x1, y2-y1), Scalar(0, 0, 0), -1);
				first = true;
				x1 = 0;
				y1 = 0;
				x2 = 0;
				y2 = 0;
			}

		}
	}


}

// Fonctionnelle
void drawRectangle_(vector<vector<int>> &numpy){
	int nbNoir = 0;
	int debut = 0;
	int fin = 0;
	for (int i = 0; i < numpy.size(); i++){
		nbNoir = 0;
		debut = 0;
		fin = 0;
		for (int j = 0; j < numpy[i].size(); j++){

			if(nbNoir == 0 && numpy[i][j] == 255){
				debut = j;
				fin = j;
				nbNoir++;
			}

			if(numpy[i][j] == 255){
				fin = j;
				nbNoir++;
			}


			if (j == numpy[i].size() - 1 && (fin-debut > 15)){
				for(int k = debut; k < fin; k++){
					numpy[i][k] = 255;
				}
			}else{
				numpy[i][debut] = 0;
				numpy[i][fin] = 0;
			}
		}	
	}
}


int main(){

	Mat img, th, cannyed_img, line_img;
	float slope = 0;

	string filename = "../../data/images/escalierb.jpg";
	img = imread(filename, 0);
	line_img = imread(filename);

	Mat black(img.rows, img.cols, CV_8UC3, cv::Scalar(0, 0, 0));
	cvtColor(black, black, cv::COLOR_BGR2GRAY);

	threshold(img, th, findBestThreshold(img, 0.5), 255, THRESH_BINARY);
	medianBlur(th, th, 3);


	// Suppression du bruit
	fastNlMeansDenoising(th, th, 30, 7, 21);

	// Canny Edge Detection
	Canny(th, cannyed_img, 100, 200);

	//////////////////////////////////////////


	// Preprocessing
	vector<vector<int>> numpy_cannyed(cannyed_img.rows);
	vector<vector<int>> numpy_black(black.rows);

	emulateNumpy(cannyed_img, numpy_cannyed);
	emulateNumpy(black, numpy_black);

	//preprocessing_(numpy_cannyed);
	preprocessing(numpy_black, numpy_cannyed);
	drawRectangle_(numpy_black);
	drawRectangle(line_img, numpy_black);

	convertNumpy2Mat(cannyed_img, numpy_cannyed); // Regarder si necessaire
	convertNumpy2Mat(black, numpy_black);



	// Programme




	//nbMarche = yy(line_img, numpy_cannyed);

	//cout << "nbMarche: " << nbMarche << endl;

/*
	// Permet de dessiner des lignes dans l'image original
	vector<Vec4i> lines;
	// HoughLinesP(cannyed_img, lines, 6, CV_PI/60, 160, 40, 25);
	HoughLinesP(cannyed_img, lines, 6, CV_PI/180, 80, 30, 10);
	// lines = cv.HoughLinesP( line_img, rho=6, theta=np.pi / 60, threshold=160, lines=[], minLineLength=40, maxLineGap=25)
	// Permet de tracer des lignes
	for( size_t i = 0; i < lines.size(); i++ ){
		slope = (lines[i][1] - lines[i][3]) / (lines[i][0] - lines[i][2]);
		if(abs(slope) >= 0.5){
			continue;
		}

		line( line_img, Point(lines[i][0], lines[i][1]),
			Point(lines[i][2], lines[i][3]), Scalar(0,0,255), 3, 8 );
	}
*/


	//////////////////////////////////////////

	
	// imshow("Display Window", img);
	imshow("Threshold Window", th);
	imshow("Cannyed Window", cannyed_img);
	imshow("Line Window", line_img);
	imshow("Black Window", black);

	waitKey(0);
	destroyAllWindows();
	return 0;

}
