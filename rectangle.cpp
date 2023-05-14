#include "rectangle.h"

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

  Rectangle::Rectangle(int a, int b) : Polygone(4), longueur(a), largeur(b){}

  int Rectangle::getLong(){
    return longueur;
  }

  int Rectangle::getLarg(){
    return largeur;
  }

  void Rectangle::putLong(int a) {
    longueur=a;
  }

    void Rectangle::putLarg(int b) {
    largeur=b;
  }
    
    
  int Rectangle::perimetre() {
    return 2*longueur+2*largeur;
  }

  void Rectangle::afficherCaracteristiques() {
    Polygone::afficherCaracteristiques();
    cout<<"La longueur du côté de ce rectangle est de : "<<longueur<<endl;
  }
  
