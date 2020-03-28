#include <iostream>
#include <cmath>
#include <vector>
#include <stdint.h>

#include <opencv2/opencv.hpp>

#include "print.h"

using namespace std;
using namespace cv;

// Retourne le meilleur threshold (50% de pixel noir - 50% de pixel blanc)
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

// Permet d'emuler d'un Numpy Array
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

// Permet de modifier les pixels d'une image à partir d'un numpy array
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

// Permet de recuperer les coordonnees des premiers et des derniers pixels et de les afficher sur une matrice noir
void printFirstLastPixelOnBlack(vector<vector<int>> &black, vector<vector<int>> &numpy){
	bool first = false; // Premiere fois qu'on rencontre un pixel blanc
	int nbBlanc = 0; // Nombre de pixel blanc rencontrer dans une ligne

	// 
	vector<int> firstPixelX;
	vector<int> firstPixelY;

	int fx=0, fy=0;
	vector<int> lastPixelX;
	vector<int> lastPixelY;

	int x1, y1, x2, y2;

	// Permet de recuperer les coordonnees des premiers et des derniers pixels
	for (int i = 0; i < numpy.size(); i++){
		lastPixelX.push_back(fx);
		lastPixelY.push_back(fy);
		first = false;
		nbBlanc = 0;
		for (int j = 0; j < numpy[i].size(); j++){

			if(numpy[i][j] == 255 && !first){
				first = true;
				firstPixelX.push_back(j);
				firstPixelY.push_back(i);
			}
			
			if(numpy[i][j] == 255){
				fx = i;
				fy = j;
			}
		}
	}
	
	// Preprocessing : Suppression du bruit
	// Si le pixel courant et le pixel suivant ont une distance superieur à 50 pixel, alors le pixel suivant est considee comme du bruit et on recommence depuis le debut
	for(int i = 0; i < firstPixelX.size(); i++){
		if(i == (firstPixelX.size() - 1)) continue;
		if(abs(firstPixelX[i] - firstPixelX[i+1]) > 50){
			firstPixelX.erase(firstPixelX.begin()+i+1);
			firstPixelY.erase(firstPixelY.begin()+i+1);
			i=0;
		} 
	}
	
	// Affiche les premiers pixels sur une matrice noir
	for(int i = 0; i < firstPixelX.size(); i++){
		//circle(img, Point(yoloX[i], yoloY[i]), 2, Scalar(0, 0, 255), -1);
		int a = firstPixelX[i];
		int b = firstPixelY[i];
		black[b][a] = 255;
	}

	// Affiche les derniers pixels sur une matrice noir
	for(int i = 0; i < lastPixelX.size(); i++){
		// circle(img, Point(finY[i], finX[i]), 2, Scalar(255, 0, 0), -1);
		int a = lastPixelY[i];
		int b = lastPixelX[i];
		black[b][a] = 255;
	}

}

// Permet de tracer une ligne entre les premiers et les derniers pixels et suppression du bruit
void matchFirstLastDrawLine(vector<vector<int>> &numpy){
	int nbNoir = 0;
	int debut = 0;
	int fin = 0;
	
	for (int i = 0; i < numpy.size(); i++){
		nbNoir = 0;
		debut = 0;
		fin = 0;
		for (int j = 0; j < numpy[i].size(); j++){

			if(nbNoir == 0 && numpy[i][j] == 255){ // Detect le premier pixel
				debut = j;
				fin = j;
				nbNoir++;
			}

			if(numpy[i][j] == 255){ // Detect le dernier pixel
				fin = j;
				nbNoir++;
			}

			if (j == numpy[i].size() - 1 && (fin-debut > 15)){ // Si la distance entre le pixel est superieur à 15, alors tout les pixels entre eux deviennent blanc
				for(int k = debut; k < fin; k++){
					numpy[i][k] = 255;
				}
			}else{ // sinon consideree comme du bruit 
				numpy[i][debut] = 0;
				numpy[i][fin] = 0;
			}
		}	
	}
}

// Permet de tracer des rectangle sur une image à partir d'un numpy array
void drawRectangle(Mat &img, vector<vector<int>> &numpy){
	bool first = true; // Permet de savoir si on a vu un pixel blanc
	int x1, y1, x2, y2; // Permet de determiner les coordonnes du rectangle
	int nbBlanc = 0; //Nombre de pixel blanc rencontree dans une ligne

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
				rectangle(img, Rect(y1, x1, y2-y1, x2-x1), Scalar(0, 255, 0), -1);
				first = true;
				x1 = 0;
				y1 = 0;
				x2 = 0;
				y2 = 0;
			}
		}
	}
}

// Permet de compter les marches en faisant un balayage vertical
int compteMarcheVertical(Mat &th, int tailleMinMarche=15){

	// Une marche minimum doit être compose de 15 pixels

	// Information concernant la matrice
	int nbLignes = th.rows;
	int nbColonnes = th.cols;
	int nbTotalElement = nbLignes * nbColonnes;
	int pas = 15;

	// Initialisation de l'algorithme
	vector<int> tabMarche; // Stocke le nombre de marche à chaque parcours
	int nbMarche = 0;
	bool changementCouleur = false;
	int pixelCourant = 0;
	int nbPixelNoir = 0;

	Scalar color(255, 255, 255);
	int positionX = 0;
	int positionY = 0;

	for(int j = 0;  j < nbColonnes; j=j+pas){
		tabMarche.push_back(nbMarche);
		nbMarche = 0;
		changementCouleur = false;
		for(int i = j; i < nbTotalElement; i=i+nbColonnes){
			positionX = i/nbColonnes;
			positionY = i%nbColonnes;
			pixelCourant = int(th.at<uint8_t>(positionX, positionY));

			if(pixelCourant == 0){
				changementCouleur = true;
				nbPixelNoir++;
			}

			if(pixelCourant == 255 && changementCouleur == true){
				if(nbPixelNoir >= tailleMinMarche){
					nbMarche++;
				}
				nbPixelNoir = 0;
            	changementCouleur = false;
			}
		}
	}
 
	// Retourner la valeur maximal
	int nombreDeMarche = *max_element(tabMarche.begin(), tabMarche.end());
	return nombreDeMarche;

}

int main(int argc, char **argv){
    vector<string> input(argv, argv + argc);
    input.erase(input.begin());

	string pathImg = input[0];
	string pathXML = input[1];

	Mat img, th, cannyed_img, line_img;

	img = imread(pathImg, 0);
	line_img = imread(pathImg);

	Mat black(img.rows, img.cols, CV_8UC3, cv::Scalar(0, 0, 0));
	cvtColor(black, black, cv::COLOR_BGR2GRAY);

	threshold(img, th, findBestThreshold(img, 0.5), 255, THRESH_BINARY);

	// Suppression du bruit
	medianBlur(th, th, 3);
	fastNlMeansDenoising(th, th, 30, 7, 21);

	// Canny Edge Detection
	Canny(th, cannyed_img, 100, 200);

	vector<vector<int>> numpy_cannyed(cannyed_img.rows);
	vector<vector<int>> numpy_black(black.rows);

	emulateNumpy(cannyed_img, numpy_cannyed);
	emulateNumpy(black, numpy_black);

	printFirstLastPixelOnBlack(numpy_black, numpy_cannyed);
	matchFirstLastDrawLine(numpy_black);

	drawRectangle(line_img, numpy_black);

	convertNumpy2Mat(cannyed_img, numpy_cannyed);
	convertNumpy2Mat(black, numpy_black);

	int marche = compteMarcheVertical(black);

	// Afficher les resultats
	system("rm -rf ../../data/.tmp/ap/*");
	system("rm -rf ../../data/.tmp/sp/*");
	system("echo '' >> ../../data/.tmp/txt/sp");
	system("echo '' >> ../../data/.tmp/txt/ap");

	printConfusionMAtrix(getNumberSteps(pathXML), marche);

	imwrite("../../data/.tmp/sp/th.jpg", th);
	imwrite("../../data/.tmp/sp/cannyed_img.jpg", cannyed_img);

	imwrite("../../data/.tmp/sp/line_img.jpg", line_img);
	imwrite("../../data/.tmp/sp/black.jpg", black);

	return 0;
}
