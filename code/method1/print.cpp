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
void printConfusionMAtrix(int real, int predictHorizontal, int predictVertical, int predictHorizontalPreprocessing, int predictVerticalPreprocessing){
    
    system("chmod 777 ../../data/.tmp/txt/sp");
    ofstream sp("../../data/.tmp/txt/sp");
    sp << "\n*************************************** Resultat ***************************************" << "\n";
    sp << "Nombre de marche                                                        : " << real << "\n";
    sp << "****************************************************************************************" << "\n";
    sp << "Nombre de marche estimee par le method Horizontale (sans Preprocessing) : " << predictHorizontal << "\n";
    sp << "Nombre de marche estimee par le method Verticale (sans Preprocessing)   : " << predictVertical << "\n";
    sp << "Taux de precision pour la méthode Horizontale (sans Preprocessing)      : " << (float(predictHorizontal)/float(real))*100 << "%" << "\n";
    sp << "Taux de precision pour la méthode Verticale (sans Preprocessing)        : " << (float(predictVertical)/float(real))*100 << "%" << "\n";
    sp << "****************************************************************************************" << "\n";
    sp.close();
    
    system("chmod 777 ../../data/.tmp/txt/sp");
    ofstream ap("../../data/.tmp/txt/ap");
    ap << "\n*************************************** Resultat ***************************************" << "\n";
    ap << "Nombre de marche                                                        : " << real << "\n";
    ap << "****************************************************************************************" << "\n";
    ap << "Nombre de marche estimee par le method Horizontale (avec Preprocessing) : " << predictHorizontalPreprocessing << "\n";
    ap << "Nombre de marche estimee par le method Verticale (avec Preprocessing)   : " << predictVerticalPreprocessing << "\n";
    ap << "Taux de precision pour la méthode Horizontale (avec Preprocessing)      : " << (float(predictHorizontalPreprocessing)/float(real))*100 << "%" << "\n";
    ap << "Taux de precision pour la méthode Verticale (avec Preprocessing)        : " << (float(predictVerticalPreprocessing)/float(real))*100 << "%" << "\n";
    ap << "****************************************************************************************" << "\n";
    ap.close();

}
