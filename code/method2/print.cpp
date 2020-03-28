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
        while (getline(fichier, ligne)) // Tant qu'on est pas à la fin, on continue de lire
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


// Ecrit les resultats dans des fichiers
void printConfusionMAtrix(int real, int predictHorizontal, int predictHorizontalPreprocessing){
    system("chmod 777 ../../data/.tmp/txt/sp");
    ofstream sp("../../data/.tmp/txt/sp");
    sp << "\n*************************************** Resultat ***************************************" << "\n";
    sp << "Nombre de marche                                                        : " << real << "\n";
    sp << "****************************************************************************************" << "\n";
    sp << "Nombre de marche estimee par le method Horizontale (sans Preprocessing) : " << predictHorizontal << "\n";
    sp << "Taux de precision pour la méthode Horizontale (sans Preprocessing)      : " << (float(predictHorizontal)/float(real))*100 << "%" << "\n";
    sp << "****************************************************************************************" << "\n";
    sp.close();
    
    system("chmod 777 ../../data/.tmp/txt/sp");
    ofstream ap("../../data/.tmp/txt/ap");
    ap << "\n*************************************** Resultat ***************************************" << "\n";
    ap << "Nombre de marche                                                        : " << real << "\n";
    ap << "****************************************************************************************" << "\n";
    ap << "Nombre de marche estimee par le method Horizontale (avec Preprocessing) : " << predictHorizontalPreprocessing << "\n";
    ap << "Taux de precision pour la méthode Horizontale (avec Preprocessing)      : " << (float(predictHorizontalPreprocessing)/float(real))*100 << "%" << "\n";
    ap << "****************************************************************************************" << "\n";
    ap.close();
}