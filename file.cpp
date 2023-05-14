#include "file.h"
#include "cellule.h"
#include "cercle.h"
#include "coloriable.h"
#include <typeinfo>
#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

File::File() {first = NULL; last = NULL; nb_elements = 0;}

int File::getNb() {
    return nb_elements;
}

Figure *File::ValeurFirst() {
    Figure  * valeur ;
    if (nb_elements==0) {
        throw 1;
        //valeur =0;
    }
    else {
        valeur = first->figure;
    }
    return valeur;

}

Figure * File::ValeurLast() {
    Figure * valeur;
    if (nb_elements==0) {
        throw 1;
        //valeur =0;
    }
    else {
        valeur = last->figure;
    }
    return valeur;

}
bool File::isEmpty() {
    bool res=false;
    if (nb_elements==0) {
        res = true;
    }
    cout<<"C'est vide ? : "<<res<<endl;
    return res;
    
}

void File::addBeginning(Figure * valeur) {
    Cellule * nouveau = new Cellule(valeur);
    nouveau->suivant = first;
    first = nouveau;

    if(nb_elements==0) last=nouveau;
    nb_elements++;

}

void File::remBeginning() {
    if (nb_elements==0) {throw Vide(); }
    else {
    Cellule * supp = first;
    first = first->suivant;
    delete supp;
    nb_elements--;

    if (nb_elements==0) {
        last = NULL;
    }
}
}

void File::display()
{
    Cellule * pointeur;
    pointeur = first;
  while ( pointeur!= NULL)
  {int i=0;
    pointeur->figure->afficherCaracteristiques();
    cout<<"Le perimètre de la figure "<<i<<" est de : "<<pointeur->figure->perimetre()<<endl;
    if (typeid(*(pointeur->figure))==typeid(Cercle)) {
        Cercle * c = dynamic_cast<Cercle *>(pointeur->figure);
        cout<<"La couleur de ce cercle est : "<<c->getCouleur()<<endl;
}
    pointeur = pointeur->suivant;
    i++;
  }
}

/* void File::remLast() {
    Cellule * avant_dernier = first;

    if (nb_elements > 0) {
        for (int i=0; i < nb_elements -1; i++) {
            avant_dernier=avant_dernier->suivant;
        }throw Vide();int
        delete avant_dernier->suivant;
        avant_dernier->suivant=NULL;
        last = avant_dernier;
    }
    
    nb_elements--;

    if (nb_elements==0) {
        last = NULL;
    }
} */

