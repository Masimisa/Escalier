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
    string ligne; //A variable to store the read lines
    string text;  //A variable to store all the text, we will make the regular expression on this variable
    if (fichier){
        while (getline(fichier, ligne))//As long as we are not at the end we continue to read
           text += ligne + '\n';
        fichier.close();
    }else{ // If we don't have the right to read
        cout << "Error: Unable to open file for reading" << endl;
        return 0;
    }

    regex const expression("e1");
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


// Matrice de Confusion
void printConfusionMAtrix(int real, int predictVertical, int predictHorizontal){
    
    system("chmod 777 ../../data/.tmp/txt/sp");
    ofstream sp("../../data/.tmp/txt/sp");

    sp << "\n*************************************** Resultat ***************************************" << endl;
    sp << "Nombre de marche                                                        : " << real << endl;
    sp << "****************************************************************************************" << endl;
    sp << "Nombre de marche estimee par le méthode Vertical                         : " << predictVertical << endl;
    sp << "Taux de precision pour la méthode Vertical                              : " << precision(float(predictVertical),float(real)) << "%" << endl;
    sp << "****************************************************************************************" << endl;
    sp << "****************************************************************************************" << endl;
    sp << "Nombre de marche estimee par le méthode Horizontal                       : " << predictHorizontal << endl;
    sp << "Taux de precision pour la méthode Horizontal                            : " << precision(float(predictHorizontal),float(real)) << "%" << endl;
    sp << "****************************************************************************************" << endl;
    
    sp.close();
    
}
