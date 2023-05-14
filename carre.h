#ifndef CARRE_H 
#define CARRE_H

#include "polygone.h"

class Carre : public Polygone {
private:
  int longueur;
public:

  Carre(int a);
  int get();
  

  void put(int a);
    
  int perimetre();

  void afficherCaracteristiques();

};


#endif
