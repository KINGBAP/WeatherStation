#include "coloriable.h"

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

 Coloriable::Coloriable(string coul){
    couleur=coul;
}
string Coloriable::getCouleur(){
return couleur;
}
void Coloriable::setCouleur(string coul){
couleur=coul;
}



