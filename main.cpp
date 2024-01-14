#include <iostream>
#include "Image.h"

// Fonction pour générer un filtre gaussien
cv::Mat generateGaussianFilter(int size, double sigma) {
    cv::Mat gaussianFilter(size, size, CV_64F);
    double sum = 0.0;

    // Calculate the Gaussian values and fill the filter matrix
    for (int i = -size/2; i <= size/2; i++) {
        for (int j = -size/2; j <= size/2; j++) {
            double value = std::exp(-(i*i + j*j) / (2.0 * sigma * sigma));
            gaussianFilter.at<double>(i + size/2, j + size/2) = value;
            sum += value;
        }
    }

    // Normalize the filter to ensure the sum of elements is 1
    gaussianFilter /= sum;

    return gaussianFilter;
}

int main() 
{
    cout << "Appuyez sur une touche pour continuer" << endl;
    cin.get();


    string path = "/home/hugo/Downloads/c++.png";

    Image myimg = Image(path, true);

    // Affichage d'une image
    myimg.Afficher();

    vector<int> taille = myimg.getSize();

    cout << "Nombre de lignes : " << taille[0] << endl;
  
    cout << "Nombre de colonnes : " << taille[1] << endl;

// Calcul de l'histogramme RGB
/*
    string s;

    cout << "Donner le nombre d'intervalle pour l'histogramme : ";
    cin  >> s;
    cout << endl;
    
    int bins = stoi(s);

    int bins = 25;

    vector<int> Myhist = myimg.Histogramme(bins);
    
    int cpt;
*/

// Affichage des éléments de l'histogramme
/*  
    for (int i : Myhist)
        std::cout << i << endl;
*/

// Convertir l'image en niveaux de gris
/*
   myimg.GreyScale();
   
   myimg.Afficher();
*/

 // Test de la convolution avec un flou gaussien 3x3
   cv::Mat gauss = generateGaussianFilter(20, 5.0);
   cout << "Convolution de l'image avec le filtre" << endl;
   myimg.Conv(gauss);
   cout << "Affichage de l'image" << endl;

   myimg.Taille();

   myimg.Afficher();

   return 0;
}
