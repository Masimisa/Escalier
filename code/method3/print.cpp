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


// Matrice de Confusion
void printConfusionMAtrix(int real, int predictVertical){
    
    system("chmod 777 ../../data/.tmp/txt/sp");
    ofstream sp("../../data/.tmp/txt/sp");
    sp << "\n*************************************** Resultat ***************************************" << "\n";
    sp << "Nombre de marche                                                        : " << real << "\n";
    sp << "****************************************************************************************" << "\n";
    sp << "Nombre de marche estimee                                                : " << predictVertical << "\n";
    sp << "Taux de precision                                                       : " << (float(predictVertical)/float(real))*100 << "%" << "\n";
    sp << "****************************************************************************************" << "\n";
    sp.close();
    
}
