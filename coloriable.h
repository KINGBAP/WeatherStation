#ifndef COLORIABLE_H 
#define COLORIABLE_H
#include<string>

using namespace std;

class Coloriable {
protected :
  string couleur;

public :

 Coloriable(string coul);
string getCouleur();
void setCouleur(string coul);

};  

#endif
