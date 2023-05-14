#include "carre.h"

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;


  Carre::Carre(int a): Polygone(4), longueur(a){}

  int Carre::get(){
    return longueur;
  }
  

  void Carre::put(int a) {
    longueur=a;
  }
    
  int Carre::perimetre() {
    return 4*longueur;
  }

  void Carre::afficherCaracteristiques() {
    Polygone::afficherCaracteristiques();
    cout<<"La longueur du côté de ce carré est de : "<<longueur<<endl;
  }



