#ifndef DESCRIPTEUR_H
#define DESCRIPTEUR_H

#include "include.h"
using namespace std;

class descripteur
{
private:
    int _id_descripteur;
    string _titre;
    string _patient;
    string _technique;
    string _type;
    int _cout;
    long _poids;
    string _source;
    int _largeur;
    int _longeur;

public:
    descripteur(std::vector<std::string> lines);
    descripteur(
        int _id_descripteur,
        string _titre,
        string _patient,
        string _technique,
        string _type,
        int _cout,
        long long int _poids,
        string _source,
        int _largeur,
        int _longeur);

    void affiche();
};

#endif // DESCRIPTEUR_H
