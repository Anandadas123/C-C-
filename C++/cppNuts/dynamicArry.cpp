#include<iostream>
using namespace std;

const int CAPACITY=100;
int main(){
  int *dArray;
  dArray = new int[CAPACITY];
  cout<<"Array"<<endl;
  for(int i=0;i<4;i++){dArray[i]=i;}
  for(int i=0;i<4;i++){cout<<dArray[i]<<" ";}
  delete [] dArray;
  dArray =NULL;
  cout<< dArray[0]<<endl;
  return 0;
}
