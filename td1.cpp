#include <iostream>
#include<algorithm>

using namespace std;

class  vecteur{
private:
  float *elements;
  int dim;

  
public:
  vecteur() {
    dim = 0;
    //cout <<"0"<<endl;
  }
  
  vecteur(int x) {
    dim = x;
    elements = new float[x];}
  
  vecteur(int x, float y) {
    dim = x;
    elements = new float[x];
    for (int i=0; i<x ; i++)  elements[i] = y;
  }

  vecteur(const vecteur& v){
    dim = v.dim;
    elements = new float[dim];
    elements = v.elements;
    // cout<<"dim: "<<dim<<endl;
  }

    
  void  get(int a){
  
    cout<<"Valeur obtenue : "<<elements[a]<<endl;
  }
  
  void affiche() {
  for (int i=0;i<dim;i++) cout<<elements[i];
  cout<<endl;
  }
  int getdim() {
  return dim;
  }
  
  float getelements(int a) {
  return elements[a];
  }

  void put(int a){
    int b;
    cout<<"Entrer une valeur"<<endl;
    cin>>b;
    elements[a]=b;
  }
  
  void putvalue(int a,float b) {
  elements[a]=b;
  }

  float & operator [](int indice) {
    return elements[indice];
  }

  float operator [] (int indice) const {
    return elements[indice];
  }

  
  vecteur & operator = (const vecteur & autre){
      vecteur res(max(dim,autre.dim));
      for (int i=0;i<min(dim,autre.dim);i++) res.elements[i]=autre.elements[i];
      for (int i=min(dim,autre.dim);i<max(autre.dim,dim);i++) res.elements[i]=0;
  
      
   

    return res;
  }
  vecteur & operator += (vecteur & autre){
    if (dim==autre.dim) {
      for (int i=0;i<dim;i++) elements[i]=autre.elements[i]+elements[i]; 
    }
   

    return (*this);
  }


};

class vecteur_intel : public  vecteur {
public:

vecteur_intel(int x) : vecteur(x) {}
  
  vecteur_intel(int x, float y) : vecteur(x,y) {}
  vecteur_intel(const vecteur& v) : vecteur(v){}

   void affiche() {
     vecteur::affiche();
   }
};

/*vecteur operator + (vecteur & un, vecteur & deux) {
    vecteur res(un.getdim());
    for(int i=0;i<res.getdim();i++) res.putvalue(i,un.getelements(i)+deux.getelements(i));
    return res;
    }*/


vecteur_intel operator + (vecteur & un, vecteur & deux) {
  vecteur_intel res(max(deux.getdim(),un.getdim()));
  if (un.getdim() <= deux.getdim()) {
  
    vecteur_intel temp(deux.getdim());
    temp=un;
    for(int i=0;i<res.getdim();i++) res.putvalue(i,temp.getelements(i)+deux.getelements(i));
  }
  else {
     vecteur_intel temp(deux.getdim());
     temp=deux;
     for(int i=0;i<res.getdim();i++) res.putvalue(i,un.getelements(i)+temp.getelements(i));
  }
    return res;
   }




int main(){
  cout<<"Début du programme"<<endl;
  /*TD1
  vecteur v1 ; // vecteur vide
  vecteur v2(50) ; // vecteur de 10 élements
  v2.put(5);
  v2.get(5);
  vecteur v3(10,1.2) ; // vecteur de 10 éléments initialiés à 1.2
  v3.get(5);
  vecteur v4(v2) ; // constructeur de recopie qui crée v4 une copie de v3
  v4.get(5);*/


  
  /*TD2
  vecteur v1 ; // vecteur vide
  vecteur v2(10) ; // vecteur de 10 élements
  vecteur v3(10,1.2) ; // vecteur de 10 éléments initialiés à 1.2
  vecteur v4(v3) ; // constructeur de recopie qui crée v4 une copie de v3
  v4.get(5);
  v4[5]=123;
  v4.get(5);
  float f;
  f=v4[5];
  cout<<"Valeur de f "<<f<<endl;
  v2=v4;
  v4[5]=3.1;
  cout<<"Valeur de V2 copie de v4: "<<v2[5]<<endl;
  //v4.operator=(v2);
  // cout<<"Valeur de v2: "<<v2[5]<<endl;
  vecteur v5(10,2);
  vecteur v6(10,3);
  vecteur v7(10);
  v7=v5+v6;
  v7.affiche();
  v7+=v5;
  v7.affiche();*/
  
  vecteur_intel v1(10,2);
  v1.affiche();
  vecteur_intel v5(8,2);
  vecteur_intel v6(10,3);
  vecteur_intel v7(10);
  v7=v5+v6;
  v7.affiche();
  
  
  
  


return(0);
}
