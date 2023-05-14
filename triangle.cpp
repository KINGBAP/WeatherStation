#include "triangle.h"

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

Triangle::Triangle(int a) : Polygone(3),cote(a) { }

  int Triangle::getCote() {
    return cote;
  }

    void Triangle::putCote(int b) {
    cote=b;
  }   
  int Triangle::perimetre() {
    return 3*cote;
  }

  void Triangle::afficherCaracteristiques() {
    Polygone::afficherCaracteristiques();
    cout<<"La longueur du côté de ce triangle équilatéral est de : "<<cote<<endl;
  }



