#include "cercle.h"

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

  Cercle::Cercle(int r,string c) :Coloriable(c),rayon(r){}

  int Cercle::getRayon() {
    return rayon;
  }

  void Cercle::putRayon(int a) {
    rayon=a;
  }

  int Cercle::perimetre() {
    return 2*3.14*rayon;
  }

  void Cercle::afficherCaracteristiques() {
    cout<<"La longueur du rayon de ce cercle est de : "<<rayon<<endl;
  }

