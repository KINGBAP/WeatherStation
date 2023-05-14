#include "cellule.h"
#include <iostream>
#include<algorithm>
#include<string>
using namespace std;


Cellule::Cellule(Figure * f) {figure=f; suivant = NULL;} 
Cellule::Cellule(Figure * f, Cellule * b) {figure=f; suivant = b;} 


