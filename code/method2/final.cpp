// Fichier Version Final
#include <iostream>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>

#include "print.h"

using namespace std;
using namespace cv;


int occurence(vector<int> tab){
	for(int x : tab){
		cout << x << " ";
	}

	cout << endl;
	int maxAppear = -1;
	int courantAppear = -1;
	int indice = -1;

	for (int i = 0; i < tab.size(); i++){
		courantAppear = count(tab.begin(), tab.end(), tab[i]);
		if(maxAppear < courantAppear){
			indice = tab[i];
			maxAppear = courantAppear;
		}
	}

	return indice;
}

int findBestThreshold(Mat img){
	Mat th;
	float nbNoir, nbBlanc, ratio;
	for (int i = 0; i < 256; i++)
	{
		threshold(img, th, i, 255, THRESH_BINARY);
		nbNoir = countNonZero(th);
		nbBlanc = (th.rows * th.cols) - countNonZero(th);
		ratio = nbBlanc / nbNoir;

		if (ratio >= 0.50)
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

// Permet de supprimer les lignes ayant un ratio de pixel noir faible
void selPoivre(vector<vector<int>> &numpy){
	int nbNoir = 0;
	for (int i = 0; i < numpy.size(); i++)
	{
		nbNoir = 0;
		for (int j = 0; j < numpy[i].size(); j++)
		{

			if (numpy[i][j] == 0)
				nbNoir++;

			if (j == numpy[i].size() - 1)
			{ // Fin de la ligne
				if (nbNoir < 35)
				{
					for (int k = 0; k < numpy[i].size(); k++)
						numpy[i][k] = 255;
				}
			}
		}
	}
}

void selPoivreVertical(vector<vector<int>> &numpy){
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

// Version Horizontale
void preprocessingBackground(vector<vector<int>> &numpy){

	int nbNoir = 0;
	int debut = 0;
	int fin = 0;
	for (int i = 0; i < numpy.size(); i++){
		nbNoir = 0;
		debut = 0;
		fin = 0;
		for (int j = 0; j < numpy[i].size(); j++){

			if(nbNoir == 0 && numpy[i][j] == 0){
				debut = j;
				fin = j;
				nbNoir++;
			}

			if(numpy[i][j] == 0){
				fin = j;
				nbNoir++;
			}


			if (j == numpy[i].size() - 1 && nbNoir > 1){
				for(int k = debut; k < fin; k++){
					numpy[i][k] = 0;
				}
			}
		}	
	}
}

void preprocessingBackground2(vector<vector<int>> &numpy){
	bool modificationEffectue = true;

	modificationEffectue = false;
	for (int i = 0; i < numpy.size(); i++){
		for (int j = 0; j < numpy[i].size(); j++){
			if(numpy[i][j] == 255){
				if(i+1 >= numpy.size() || i-1 <= 0 || j+1 >= numpy[i].size() || j-1 <= 0)
					continue;
				// (gauche, haut); (droite,haut); (gauche, bas), (droite, bas)
				if( (numpy[i][j-1] == 0 && numpy[i-1][j] == 0) || (numpy[i][j+1] == 0 && numpy[i-1][j] == 0) || (numpy[i][j-1] == 0 && numpy[i+1][j] == 0) || (numpy[i][j+1] == 0 && numpy[i+1][j] == 0) ){
					numpy[i][j] = 0;
					modificationEffectue = true;
				}
			}
		}	
	}
}

int compteMarcheHorizontal(Mat &img, Mat &th){
	// Information concernant la matrice
	int nbLignes = th.rows;
	int nbColonnes = th.cols;
	int nbTotalElement = nbLignes * nbColonnes;

	// Initialisation de l'algorithme
	vector<int> tabMarche;
	int nbMarche = 0;
	bool changementCouleur = false;
	int pixelCourant = 0;
	int nbPixelNoir = 0;

	Scalar color(255, 255, 255);
	int positionX = 0;
	int positionY = 0;

	int i = 0; //Permet de determiner la fin d'une ligne verifier la position du i++ avec un exemple simple
	int nbLigneNoir = 0;

	// S'assurer qu'on a une ligne noir continu
	for(int j = 0; j < nbTotalElement; j++){
		positionY = i%nbColonnes;
		//cout << "(" << positionX << ", " << positionY << ")" << endl;

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

void functionLess(vector<vector<int>> &numpyXor, vector<vector<int>> &numpy){
	for (int i = 0; i < numpy.size(); i++){
		for (int j = 0; j < numpy[i].size(); j++){
			if(numpyXor[i][j] == 0)
				numpy[i][j] = 255;
		}
	}
}

int main(int argc, char **argv){

    vector<string> input(argv, argv + argc);
    input.erase(input.begin());

	//string pathImg = input[0];
	//string pathXML = input[1];

	string pathImg = "../../data/images/escalier.jpg";
	string pathXML = "../../xml/escalier.xml";

	//Lecture Image
	Mat img, th, imgPreprocessing, thPreprocessing;

	int methodHorizontal = 0;
	int methodHorizontalPreprocessing = 0;

	img = imread(pathImg, 0);
	imgPreprocessing = imread(pathImg, 0);

	
	// Size size(600,600);
	// resize(img, img,size);
	// resize(imgPreprocessing, imgPreprocessing,size);

	// Transformation (Threshold + Blur)
	threshold(img, th, findBestThreshold(img), 255, THRESH_BINARY);
	threshold(imgPreprocessing, thPreprocessing, findBestThreshold(imgPreprocessing), 255, THRESH_BINARY);

	medianBlur(th, th, 5);
	medianBlur(thPreprocessing, thPreprocessing, 5);

	methodHorizontal = compteMarcheHorizontal(img, th);

	// Numpy
	vector<vector<int>> numpy(thPreprocessing.rows);
	emulateNumpy(thPreprocessing, numpy);
	
	
	// Preprocessing
	selPoivreVertical(numpy);
	selPoivre(numpy);
	
	preprocessingBackground(numpy);
	preprocessingBackground2(numpy);
 

	// Appliquer les changement effectuer sur Numpy
	convertNumpy2Mat(thPreprocessing, numpy);

	methodHorizontalPreprocessing = compteMarcheHorizontal(imgPreprocessing, thPreprocessing);

	// Afficher les resultats

	system("rm -rf ../../data/.tmp/ap/*");
	system("rm -rf ../../data/.tmp/sp/*");
	system("echo '' >> ../../data/.tmp/txt/sp");
	system("echo '' >> ../../data/.tmp/txt/ap");

	printConfusionMAtrix(getNumberSteps(pathXML), methodHorizontal, methodHorizontalPreprocessing);
	
	//imshow("Display Window", img);
	//imshow("Threshold Window", th);
	
	imwrite("../../data/.tmp/sp/preprocessing.jpg", th);
	imwrite("../../data/.tmp/sp/final.jpg", img);

	//imshow("Display Window Preprocessing", imgPreprocessing);
	//imshow("Threshold Window Preprocessing", thPreprocessing);

	imwrite("../../data/.tmp/ap/preprocessing.jpg", thPreprocessing);
	imwrite("../../data/.tmp/ap/final.jpg", imgPreprocessing);

	// waitKey(0);
	// destroyAllWindows();
	return 0;
}
