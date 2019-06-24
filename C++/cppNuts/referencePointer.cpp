
#include<iostream>
using namespace std;


int main(){
  int i=10;
  int &r =i;
  int *p = &i;
  
  int var =90;
  //r =var;
  p = &var;
  *p = 60;
  
  cout<< &i << '\t' << &r << '\t' << &p <<endl;
  cout<<"my name is \"khan\" "<<endl;

}

