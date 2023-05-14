#ifndef RECTANGLE_H 
#define RECTANGLE_H

#include "polygone.h"


class Rectangle : public Polygone {
private:
  int longueur;
  int largeur;
public:

  Rectangle(int a, int b) ;

  int getLong();

  int getLarg();
  void putLong(int a) ;

    void putLarg(int b) ;
    
    
  int perimetre() ;

  void afficherCaracteristiques();


};


#endif
