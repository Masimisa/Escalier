#include <iostream>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>

#include "print.h"

using namespace std;
using namespace cv;

// Retourne le meilleur threshold (50% de pixel noir - 50% de pixel blanc)
int findBestThreshold(Mat img){
	Mat th;
	float nbNoir, nbBlanc, ratio;
	for (int i = 0; i < 256; i++){
		threshold(img, th, i, 255, THRESH_BINARY);
		nbNoir = countNonZero(th);
		nbBlanc = (th.rows * th.cols) - countNonZero(th);
		ratio = nbBlanc / nbNoir;

		if (ratio >= 0.50)
			return i;
	}
}

// Retourne le nombre de marche à partir d'un tableau.
int getNbMarche(vector<int> tab){

	// On trie le tableau dans l'ordre decroissant
	sort (tab.begin(), tab.end(),greater<int>());

	int premier = 0;
	int second = 0;
	int n = 0;
	int m = 0;

	while (true){

		// On recupere l'element maximal
		premier = tab[0];
		n = 0;
			
		// On regarde le nombre de fois qu'il apparait dans le vector
		for (auto i = tab.begin(); i != tab.end(); i++) { 			
			if(premier == *i){
				n++;
			}
		}		

		// On supprime l'element maximal
		std::remove(tab.begin(), tab.end(), premier);

		// On recupere le second element maximal
		second = tab[0];
		m = 0;
		
		// On regarde le nombre de fois qu'il apparait dans le vector
		for (auto i = tab.begin(); i != tab.end(); i++) { 
			if(second == *i){
				m++;
			}
		}

		// On supprime l'element maximal
		std::remove(tab.begin(), tab.end(), premier);

		// On retourne l'element maximal qui à la plus grande frequence
		if (n >= m) {
			return premier;
		}
	}
}

// Permet de compter les marches en faisant un balayage vertical
int compteMarcheVertical(Mat &img, Mat &th, int tailleMinMarche=15){

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
					circle(img, Point(positionY, positionX), 3, color, -1);
					nbMarche++;
				}
				nbPixelNoir = 0;
            	changementCouleur = false;
			}
		}
	}
 
	// Retourne l'element maximal avec la plus grande frequence
	int nombreDeMarche = getNbMarche(tabMarche);
	return nombreDeMarche;
}

// Permet de compter les marches en faisant un balayage vertical
int compteMarcheHorizontal(Mat &img, Mat &th){

	// Information concernant la matrice
	int nbLignes = th.rows;
	int nbColonnes = th.cols;
	int nbTotalElement = nbLignes * nbColonnes;

	// Initialisation de l'algorithme
	vector<int> tabMarche; // Stocke le nombre de marche à chaque parcours
	int nbMarche = 0;
	bool changementCouleur = false;
	int pixelCourant = 0;
	int nbPixelNoir = 0;

	Scalar color(255, 255, 255);
	int positionX = 0;
	int positionY = 0;

	int i = 0;
	int nbLigneNoir = 0;

	for(int j = 0; j < nbTotalElement; j++){

		positionY = i%nbColonnes;
		pixelCourant = int(th.at<uint8_t>(positionX, positionY));

		if(pixelCourant == 0){
			if(nbPixelNoir == 0){ // Compte le nombre de pixel noir dans la ligne
				circle(img, Point(positionY, positionX), 2, color, -1);
			}
			nbPixelNoir++;
		}

		i++;
		if(i >= nbColonnes){ // Longueur d'une ligne
			positionX++;

			if(nbPixelNoir > 5){ // Nombre de pixel noir dans la ligne
				nbLigneNoir++;
			}

			if(nbPixelNoir == 0 || i == nbTotalElement){
				if(nbLigneNoir > 5){
					nbMarche++;
					nbLigneNoir = 0;			
				}
			}
			nbPixelNoir = 0;
			i = 0;
		}
	}
	return nbMarche;
}

int main(int argc, char **argv){

	// Input Utilisateur
    vector<string> input(argv, argv + argc);
    input.erase(input.begin());

	string pathImg = input[0];
	string pathXML = input[1];


	//Lecture Image
	Mat imgV, imgH, th;
	int methodVertical = 0;
	int methodHorizontal = 0;

	imgV = imread(pathImg, 0);
	imgH = imread(pathImg, 0);

	// Transformation (Threshold + Blur)
	threshold(imgV, th, findBestThreshold(imgV), 255, THRESH_BINARY);
	medianBlur(th, th, 5);

	methodHorizontal = compteMarcheHorizontal(imgH, th);
	methodVertical = compteMarcheVertical(imgV, th);

	// Afficher les Resultats
	system("rm -rf ../../data/.tmp/ap/*");
	system("rm -rf ../../data/.tmp/sp/*");
	system("echo '' >> ../../data/.tmp/txt/sp");
	system("echo '' >> ../../data/.tmp/txt/ap");

	printConfusionMAtrix(getNumberSteps(pathXML), methodVertical, methodHorizontal);

	imwrite("../../data/.tmp/sp/preprocessing.jpg", th);
	imwrite("../../data/.tmp/sp/final.jpg", imgV);

	imwrite("../../data/.tmp/ap/preprocessing.jpg", th);
	imwrite("../../data/.tmp/ap/final.jpg", imgH);

	return 0;
}
