#ifndef FILE_H 
#define FILE_H
#include "cellule.h"
#include <iostream>

using namespace std;




class File {
private : 
Cellule * first;
Cellule * last;
int nb_elements;

public:

File();

int getNb() ;
Figure * ValeurFirst();
Figure * ValeurLast();
bool isEmpty() ;

void addBeginning(Figure * a);
void remBeginning();
void display();
//void remLast();



};

class Vide : public exception {
public:


};
#endif
