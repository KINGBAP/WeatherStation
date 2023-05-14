#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

class Figure {
private:
  static int cpt;
public:
  Figure() {cpt++;}
  virtual int perimetre()=0;
  virtual void afficherCaracteristiques()=0;
  static int getCpt() {
    return cpt;
  }
 
};
int Figure::cpt=0;

class Polygone : public Figure {
private:
  int nbCotes;
  
public:

  Polygone(int a){
    nbCotes=a;
  }
  
  void afficherCaracteristiques(){
    cout<<"Le nombre de côtés est de : "<<nbCotes<<endl;
  }

};

class Rectangle : public Polygone {
private:
  int longueur;
  int largeur;
public:

  Rectangle(int a, int b) : Polygone(4), longueur(a), largeur(b){}

  int getLong(){
    return longueur;
  }

  int getLarg(){
    return largeur;
  }

  void putLong(int a) {
    longueur=a;
  }

    void putLarg(int b) {
    largeur=b;
  }
    
    
  int perimetre() {
    return 2*longueur+2*largeur;
  }

  void afficherCaracteristiques() {
    Polygone::afficherCaracteristiques();
    cout<<"La longueur du côté de ce rectangle est de : "<<longueur<<endl;
  }
  


};


class Carre : public Polygone {
private:
  int longueur;
public:

  Carre(int a): Polygone(4), longueur(a){}

  int get(){
    return longueur;
  }
  

  void put(int a) {
    longueur=a;
  static int cpt;
  }
    
  int perimetre() {
    return 4*longueur;
  }

  void afficherCaracteristiques() {
    Polygone::afficherCaracteristiques();
    cout<<"La longueur du côté de ce carré est de : "<<longueur<<endl;
  }


};

class TriangleEquilateral : public Polygone {
private:
int cote;

public: 


TriangleEquilateral(int a) : Polygone(3),cote(a) { }

  int getCote() {
    return cote;
  }

    void putCote(int b) {
    cote=b;
  }
    
  int perimetre() {
    return 3*cote;
  }

  void afficherCaracteristiques() {
    Polygone::afficherCaracteristiques();
    cout<<"La longueur du côté de ce triangle équilatéral est de : "<<cote<<endl;
  }

}; 

class Coloriable {
protected :
  string couleur;

public :

 Coloriable(string coul){
    couleur=coul;
}
string getCouleur(){
return couleur;
}
void setCouleur(string coul){
couleur=coul;
}
};  

class Cercle : public Figure, public Coloriable {
  private:
  int rayon;

  public:

  Cercle(int r,string c) :Coloriable(c),rayon(r){}

  int getRayon() {
    return rayon;
  }

  void putRayon(int a) {
    rayon=a;
  }

  int perimetre() {
    return 2*3.14*rayon;
  }

  void afficherCaracteristiques() {
    cout<<"La longueur du rayon de ce cercle est de : "<<rayon<<endl;
  }



};

class Cellule {
  private:
  public :
  
};

class File {


};



int main() {
  // cercle1.afficherCaracteristiques();
  Carre carre1(4);
  Rectangle r1(2,3);
  TriangleEquilateral triangle1(3);
  Cercle cercle1(5,"rouge");
  // cout<<carre1.perimetre()<<endl;
  // carre1.afficherCaracteristiques();
  // r1.afficherCaracteristiques();
  // cout<<r1.perimetre()<<endl;
  // triangle1.afficherCaracteristiques();

  Figure *tab[3];
  tab[0]=&carre1;
  tab[1]=&triangle1;
  tab[2]=&cercle1;

  for (int i=0;i<3;i++) {
    cout<<"Le perimètre de la figure "<<i<<" est de : "<<tab[i]->perimetre()<<endl;
    tab[i]->afficherCaracteristiques();
  }
  cout<<tab[2]->getCpt()<<endl;
cout<<cercle1.getCouleur()<<endl;

}
  