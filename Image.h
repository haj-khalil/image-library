#pragma once
#ifndef IMAGE_H__
#define IMAGE_H__

#include <opencv2/opencv.hpp>
#include <string>	// Bibliotheque pour la gestion des chaines de caracteres
#include <vector>
#include <cmath>
#include <matplot/matplot.h>

using namespace std;



class Image {
private:
    cv::Mat _image;
    vector<int> _taille;
    bool _multicanal;

public:
    // Constructors
    Image(std::string path, bool multicanal);
    Image();

    // Getters
    cv::Mat getImage();
    std::vector<int> getSize();
    bool getMulticanal();

    // Setters
    void setImage(cv::Mat img);
    void setMulticanal(bool multicanal);

    // Methods
    void Afficher();
    void Taille();
    vector<int> Histogramme(int bins = 10);
    void Inverser();
    void Seuillage(int S);
    void GreyScale();

    // Fonction pour la convolution 
    void Conv(cv::Mat filter);
};


#endif
