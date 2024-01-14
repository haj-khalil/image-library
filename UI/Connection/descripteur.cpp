#include "descripteur.h"
#include "include.h"

descripteur :: descripteur(std::vector<std::string> lines){
_id_descripteur = stoi(lines[0]);
_titre = lines[1].c_str();
_patient = lines[2].c_str();
_technique = lines[3].c_str();
_type = (lines[4].c_str());
_cout = stoi(lines[5]);
_poids =stol(lines[6]);
_source = lines[7].c_str();
_largeur = stoi(lines[8]);
_longeur = stoi(lines[9]);
}


void descripteur ::affiche(){
    cout<< "this id is : "<<_id_descripteur<<"\n"; 
    cout<< "this id is : "<<_titre<<"\n"; 
    cout<< "this id is : "<<_patient<<"\n";
    cout<< "this id is : "<<_technique<<"\n"; 
    cout<< "this id is : "<<_type<<"\n"; 
    cout<< "this id is : "<<_cout<<"\n"; 
    cout<< "this id is : "<<_poids<<"\n"; 
    cout<< "this id is : "<<_source<<"\n"; 
    cout<< "this id is : "<<_largeur<<"\n"; 
    cout<< "this id is : "<<_longeur<<"\n"; 
}
