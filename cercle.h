#ifndef CERCLE_H 
#define CERCLE_H

#include "figure.h"
#include "coloriable.h"


class Cercle : public Figure, public Coloriable {
  private:
  int rayon;

  public:

  Cercle(int r,string c);

  int getRayon();

  void putRayon(int a);
  int perimetre();

  void afficherCaracteristiques();


};


#endif
