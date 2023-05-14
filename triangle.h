#ifndef TRIANGLE_H 
#define TRIANGLE_H

#include "polygone.h"

class Triangle : public Polygone {
private:
int cote;

public: 


Triangle(int a) ;

  int getCote() ;
    void putCote(int b);
  int perimetre() ;

  void afficherCaracteristiques() ;
  
  };

#endif
