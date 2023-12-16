#ifndef IMAGE_H__
#define IMAGE_H__

#include <opencv2/opencv.hpp>
#include <string>	// Bibliotheque pour la gestion des chaines de caracteres
using namespace std;



class Image {
private:
    Mat _image;
    int[2] _taille;
    bool _multicanal;

public:
    Image(std::string type, double quantite, double prix);
};


#endif