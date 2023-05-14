#include "polygone.h"

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;


  Polygone::Polygone(int a){
    nbCotes=a;
  }
  
  void Polygone::afficherCaracteristiques(){
    cout<<"Le nombre de côtés est de : "<<nbCotes<<endl;
  }



