#include "Image.h"

// Constructors
Image::Image(std::string path, bool multicanal)
{
	_image = cv::imread(path);
	_multicanal = true;
	_taille.resize(2);
	_taille[0] = _image.rows;
	_taille[1] = _image.cols;
}

Image::Image()
{
	_image = cv::Mat();
	_multicanal = false;
	_taille.resize(2);
	_taille[0] = _image.rows;
	_taille[1] = _image.cols;

}

// Getters
cv::Mat Image::getImage()
{
	return _image;
}

std::vector<int> Image::getSize()
{
	return _taille;
}

bool Image::getMulticanal()
{
	return _multicanal;
}

// Setters
void Image::setImage(cv::Mat img)
{
	_image = img;
	_taille[0] = _image.rows;
	_taille[1] = _image.cols;
}

void Image::setMulticanal(bool multicanal)
{
	_multicanal = multicanal;
}


// Methods
void Image::Afficher()
{
// Ajouter fonctionalité pour modifier la taille de la fenêtre
	cv::namedWindow("Affichage de l'image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Affichage de l'image", _image);
	cv::moveWindow("Affichage de l'image", 0, 45);
	cv::waitKey(0);
	cv::destroyAllWindows();
}

// Afficher la taille d'une image sur un terminal
void Image::Taille()
{
	cout << "Nombre de lignes : " << _taille[0] << endl;
	cout << "Nombre de colonnes : " << _taille[1] << endl;
}

// Tracer l'histogramme des couleurs RGB d'une image
vector<int> Image::Histogramme(int bins)
{
	double minVal, maxVal;
	cv::minMaxLoc(_image, &minVal, &maxVal);

	double width = (maxVal - minVal) / bins;

	vector<int> histo_R, histo_G, histo_B, x_axis;

	histo_R.resize(bins);
	histo_G.resize(bins);
	histo_B.resize(bins);
	
	// Vecteur pour stocker les valeurs d'abscisse x
	x_axis.resize(bins);
	for (int k = 0; k < bins; k++) {
		x_axis[k] = k*width;
	}

	for (int i = 0; i < _taille[0]; i++) {
		for (int j = 0; j < _taille[1]; j++) {
			double val_R = _image.at<cv::Vec3b>(i, j)[0];
			double val_G = _image.at<cv::Vec3b>(i, j)[1];
			double val_B = _image.at<cv::Vec3b>(i, j)[1];

			for (int k = 0; k < bins; k++) {
				if (val_R > (minVal + k * width) and val_R < (minVal + (k + 1) * width))
					histo_R[k] += 1;
				if (val_G > (minVal + k * width) and val_G < (minVal + (k + 1) * width))
					histo_G[k] += 1;
				if (val_B > (minVal + k * width) and val_B < (minVal + (k + 1) * width))
					histo_B[k] += 1;
			}
		}
	}

	matplot::subplot(3,1,1);
	matplot::bar(x_axis, histo_R)->face_color("r");
	
	matplot::subplot(3,1,2);
	matplot::bar(x_axis, histo_G)->face_color("g");
	
	matplot::subplot(3,1,3);
	matplot::bar(x_axis, histo_B)->face_color("b");
	matplot::show();

	return histo_R;
}

// Transformer une image en couleur en image en niveau de gris
void Image::GreyScale()
{
	for (int i = 0; i < _taille[0]; i++) {
		for (int j = 0; j < _taille[1]; j++) {
			double val_R = _image.at<cv::Vec3b>(i, j)[0];
			double val_G = _image.at<cv::Vec3b>(i, j)[1];
			double val_B = _image.at<cv::Vec3b>(i, j)[1];
			
			int val = (val_R + val_G + val_B)/3;

			_image.at<cv::Vec3b>(i, j)[0] = val;
			_image.at<cv::Vec3b>(i, j)[1] = val;
			_image.at<cv::Vec3b>(i, j)[2] = val;
		}
	}
	
	_multicanal = false;
}

// Fonction pour la convolution entre une image de base et une image (filtre)
// Condition sur les bords : =0 en dehors de l'image
void Image::Conv(cv::Mat filter){
	int N;
	double val_R, val_G, val_B;
	bool cond;

	for (int i = 0; i < _taille[0]; i++) {
		for (int j = 0; j < _taille[1]; j++){

			val_R = 0;
			val_G = 0;
			val_B = 0;
			

			for (int k = -filter.rows/2; k <= filter.rows/2; k++){
				for (int l = -filter.cols/2; l <= filter.cols/2; l++){

					cond = i+k>0 && j+l>0 && i+k<_taille[0] && j+l<_taille[1];

					if (cond){
						val_R += _image.at<cv::Vec3b>(i+k, j+l)[0] * filter.at<double>(k+filter.rows/2, l+filter.cols/2);
						val_G += _image.at<cv::Vec3b>(i+k, j+l)[1] * filter.at<double>(k+filter.rows/2, l+filter.cols/2);
						val_B += _image.at<cv::Vec3b>(i+k, j+l)[2] * filter.at<double>(k+filter.rows/2, l+filter.cols/2);
						//cout << "Val : " << val << " | pixel de l'image :" << _image.at<cv::Vec3b>(i+k, j+l)[0] << " | pixel du filtre :" << filter.at<double>(k+filter.rows/2, l+filter.cols/2) << endl;
					
						if (i+k>_taille[0]) cout << "taille 0 : " << _taille[0] << " | " << i+k << endl;
						if (j+l>_taille[1]) cout << "taille 1 : " << _taille[1] << " | " << j+l << endl;
						if (k+filter.rows/2>filter.rows) cout << "Filter lines : " << filter.rows << " | " << k+filter.rows/2 << endl;
						if (l+filter.cols/2>filter.cols) cout << "Filter colunms : " << filter.cols << " | " << l+filter.cols << endl;
					}
//					cout << "--->" << (i+k>0 && j+l>0 && i+k<_taille[0] && j+l<_taille[1]) << endl;
				}
			}

			// _image prend la valeur de val si elle est inférieure à 255, elle prend 255 sinon
			_image.at<cv::Vec3b>(i, j)[0] = (val_R > 255) ? 255 : val_R;
			_image.at<cv::Vec3b>(i, j)[1] = (val_G > 255) ? 255 : val_G;
			_image.at<cv::Vec3b>(i, j)[2] = (val_B > 255) ? 255 : val_B;
		}
	}
}