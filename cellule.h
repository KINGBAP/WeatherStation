#ifndef CELLULE_H 
#define CELLULE_H
#include "figure.h"


class Cellule {
  private:
  Figure * figure;
  Cellule * suivant;

  Cellule(Figure * f);
  Cellule(Figure * f, Cellule * b);
  public:
  
  friend class File; 

};


#endif
