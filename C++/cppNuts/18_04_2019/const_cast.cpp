#include<iostream>
#include<string.h>
using namespace std;

// class Int {
//   int x;
// public:
//   Int(int x=0):x{x}{
//     cout<<"conversion constructor"<<endl;
//   }
//   operator string () {
//     cout<<"conversion operator"<<endl;
//     return to_string(x);
//   }
// };

int main(){
  const int a1=10;
  const int *b1 = &a1;
  int *d1 = const_cast<int*>(b1);
  *d1=15;

  cout<<a1<<endl;
  cout<<*d1<<endl;

  int a2 =20;
  const int *b2 = &a2;
  int *d2 = const_cast<int*>(b2);
  *d2=30;
}
