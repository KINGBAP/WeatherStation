#ifndef POLYGONE_H 
#define POLYGONE_H

#include "figure.h"

class Polygone : public Figure {
private:
  int nbCotes;
  
public:

  Polygone(int a);
  
  void afficherCaracteristiques();
};

#endif
