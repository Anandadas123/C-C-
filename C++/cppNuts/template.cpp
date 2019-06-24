#include<iostream>
using namespace std;

template <typename T>
T getMax(T a, T b){
  return (a>b)?a:b;
}

int main(){
  int a=10,b=20;
  cout<< getMax<int>(a,b) <<endl;
  char c1='a',c2='b';
  cout<< static_cast<char>(getMax<char>(c1,c2)) <<endl;
  return 0;
}

