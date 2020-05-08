#include <iostream>
#include <vector>
#include <stdint.h>
#include <regex>

#include <fstream>
#include <string>

#include "print.h"

using namespace std;

// Retourne le nombre de pas dans un escalier a partir d'un fichier XML
int getNumberSteps(string filename){
    ifstream fichier(filename);
    string ligne; // Varaible qui stock les lignes lues
    string text;  // Variable qui stock tout le texte, nous allons faire une expression reguliere sur cette variable
    if (fichier){
        while (getline(fichier, ligne))// Tant qu'on est pas à la fin, on continue de lire
           text += ligne + '\n';
        fichier.close();
    }else{ // Si on a pas le droit de lire
        cout << "Error: Unable to open file for reading" << endl;
        return 0;
    }

    regex const expression("e1"); // Dans un fichier XML, une marche se definie par 'e1'
    smatch matches;
    ptrdiff_t const match_count(std::distance(std::sregex_iterator(text.begin(), text.end(), expression), std::sregex_iterator()));
    return match_count;
}

// Retourne le taux de precision
int precision(float predict, float real) {
    float result = (predict / real) * 100;
    if (result <= 100){
        return result;
    }

    result = 100 - (result - 100);
    return result;
}

// Affiche les differents taux de precision des differentes methodes
void printConfusionMAtrix(int real, int predictVertical, int predictHorizontal){
    cout << "\n*************************************** Resultat ***************************************" << endl;
    cout << "Nombre de marche                                                        : " << real << endl;
    cout << "****************************************************************************************" << endl;
    cout << "Nombre de marche estimee par le méthode Vertical                         : " << predictVertical << endl;
    cout << "Taux de precision pour la méthode Vertical                              : " << precision(float(predictVertical),float(real)) << "%" << endl;
    cout << "****************************************************************************************" << endl;
    cout << "****************************************************************************************" << endl;
    cout << "Nombre de marche estimee par le méthode Horizontal                       : " << predictHorizontal << endl;
    cout << "Taux de precision pour la méthode Horizontal                            : " << precision(float(predictHorizontal),float(real)) << "%" << endl;
    cout << "****************************************************************************************" << endl;
}
