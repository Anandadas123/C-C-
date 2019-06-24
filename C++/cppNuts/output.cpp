#include<iostream>
using namespace std;

int main() {

  int i=10,j=2;
  int *ip = &i, *jp= &j;
  cout<< *ip / *jp<<endl;
}
