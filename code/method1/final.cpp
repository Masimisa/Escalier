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
	for (int i = 0; i < nbTotalElement; i++){
		positionX = i / nbColonnes;
		positionY = i % nbColonnes;
		img.at<uint8_t>(positionX, positionY) = numpy[positionX][positionY];
	}
}

// Permet de supprimer les lignes ayant un ratio de pixel noir faible
void lineRatioPixelSmall(vector<vector<int>> &numpy){
	int nbNoir = 0;
	for (int i = 0; i < numpy.size(); i++){
		nbNoir = 0;
		for (int j = 0; j < numpy[i].size(); j++){
			if (numpy[i][j] == 0)
				nbNoir++;

			if (j == numpy[i].size() - 1){ // Fin de la ligne
				if (nbNoir < 35){ // On suppose q'une ligne doit contenir au moins 35 pixels noir
					for (int k = 0; k < numpy[i].size(); k++)
						numpy[i][k] = 255;
				}
			}
		}
	}
}

// Permet de supprimer les colonnes ayant un ratio de pixel noir faible
void columnRatioPixelSmall(vector<vector<int>> &numpy){
	bool changement = true;

	int nbNoir = 0;
	int n = 0;
	int i = 0;
	i++;
	changement = false;
	for(int i=0; i<numpy.size(); i++){
		nbNoir = 0;
		n = 0;
		for(int j=0; j<numpy[i].size(); j++){

			// Dès qu'on detecte un pixel noir, on regarde les 6 pixels du haut et les 6 pixels du bas
			// Si aucun pixel n oir n'a etait trouve, alors on le met en blanc
			if(numpy[i][j] == 0){
				if(i+6>numpy.size() || j-6 < 0 || i-6 < 0  || j+6 > numpy[i].size()){
					continue;
				}else{
					for(int k=1; k<6; k++){
						nbNoir += numpy[i+k][j];
						nbNoir += numpy[i][j-k];
						n += 255+255; 
					}
					if(nbNoir == n){
						numpy[i][j] = 255;				
						changement = true;
					}
				}
			}
		}
	}
}

// Permet de mettre en noir tout les pixels situe entre le premier et le dernier pixel noir de la ligne
void detectFirstLastPixelDrawLine(vector<vector<int>> &numpy){

	int nbNoir = 0;
	int debut = 0;
	int fin = 0;
	for (int i = 0; i < numpy.size(); i++){
		nbNoir = 0;
		debut = 0;
		fin = 0;
		for (int j = 0; j < numpy[i].size(); j++){

			// Detecte la position du premier pixel noir 
			if(nbNoir == 0 && numpy[i][j] == 0){
				debut = j;
				fin = j;
				nbNoir++;
			}

			// Detect la position du dernier pixel noir
			if(numpy[i][j] == 0){
				fin = j;
				nbNoir++;
			}

			// Mise en noir des pixels
			if (j == numpy[i].size() - 1 && nbNoir > 1){
				for(int k = debut; k < fin; k++){
					numpy[i][k] = 0;
				}
			}
		}	
	}
}

// Modifie la couleur d'un pixel, en fonction des pixels voisins
void changeColorOnNeighbors(vector<vector<int>> &numpy){
	for (int i = 0; i < numpy.size(); i++){
		for (int j = 0; j < numpy[i].size(); j++){
			// Si le pixel courant est blanc et que ses voisins sont noirs, alors le pixel devient noir
			if(numpy[i][j] == 255){
				if(i+1 >= numpy.size() || i-1 <= 0 || j+1 >= numpy[i].size() || j-1 <= 0)
					continue;
				// Position des differents voisins : (gauche, haut); (droite,haut); (gauche, bas), (droite, bas)
				if( (numpy[i][j-1] == 0 && numpy[i-1][j] == 0) || (numpy[i][j+1] == 0 && numpy[i-1][j] == 0) || (numpy[i][j-1] == 0 && numpy[i+1][j] == 0) || (numpy[i][j+1] == 0 && numpy[i+1][j] == 0) ){
					numpy[i][j] = 0;
				}
			}
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
 
	// Retourner la valeur maximal
	int nombreDeMarche = *max_element(tabMarche.begin(), tabMarche.end());
	return nombreDeMarche;
}

int main(int argc, char **argv){

	// Input Utilisateur
    vector<string> input(argv, argv + argc);
    input.erase(input.begin());

	string pathImg = input[0];
	string pathXML = input[1];


	//Lecture Image
	Mat img, th, imgPreprocessing, thPreprocessing;

	int methodVertical = 0;
	int methodVerticalPreprocessing = 0;

	img = imread(pathImg, 0);
	imgPreprocessing = imread(pathImg, 0);


	// Transformation (Threshold + Blur)
	threshold(img, th, findBestThreshold(img), 255, THRESH_BINARY);
	threshold(imgPreprocessing, thPreprocessing, findBestThreshold(imgPreprocessing), 255, THRESH_BINARY);

	medianBlur(th, th, 5);
	medianBlur(thPreprocessing, thPreprocessing, 5);

	methodVertical = compteMarcheVertical(img, th);


	// Numpy array
	vector<vector<int>> numpy(thPreprocessing.rows);
	emulateNumpy(thPreprocessing, numpy);
	
	
	// Preprocessing
	columnRatioPixelSmall(numpy);
	lineRatioPixelSmall(numpy);
	detectFirstLastPixelDrawLine(numpy);
	changeColorOnNeighbors(numpy);
 

	// Appliquer sur Mat les changements appliquer sur Numpy
	convertNumpy2Mat(thPreprocessing, numpy);


	// Compte les marches
	methodVerticalPreprocessing = compteMarcheVertical(imgPreprocessing, thPreprocessing, 3);


	// Afficher les Resultats
	system("rm -rf ../../data/.tmp/ap/*");
	system("rm -rf ../../data/.tmp/sp/*");
	system("echo '' >> ../../data/.tmp/txt/sp");
	system("echo '' >> ../../data/.tmp/txt/ap");

	printConfusionMAtrix(getNumberSteps(pathXML), methodVertical, methodVerticalPreprocessing);

	imwrite("../../data/.tmp/sp/preprocessing.jpg", th);
	imwrite("../../data/.tmp/sp/final.jpg", img);

	imwrite("../../data/.tmp/ap/preprocessing.jpg", thPreprocessing);
	imwrite("../../data/.tmp/ap/final.jpg", imgPreprocessing);

	return 0;
}
