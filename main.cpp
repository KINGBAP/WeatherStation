#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main() {
vector<double> v1;
vector<double> v2;

for(int i=0; i<10; i++){

v1.push_back((float)i/10.0);
}
v2=v1;


for(int i = 0; i<5; i++){
 v2.pop_back();
 }

for(long unsigned int i=0; i<v1.size(); i++) {
cout << v1[i] << " ";

}
cout<<endl;
for(long unsigned int i=0; i<v2.size(); i++) {
cout << v2[i] << " ";

}
cout << endl;


list<char> l1,l2;
list<char>::iterator it;
  char actuel = 'a';
for(int i=0;i<10;i++) {
    l1.push_front('actuel');
    actuel++;
}

for(it=l1.begin(); it!=l1.end(); it++) cout << *it << " ";
return 0;
}


