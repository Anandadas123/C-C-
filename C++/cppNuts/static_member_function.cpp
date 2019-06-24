#include<iostream>
using namespace std;

class Base{
public:
  int x;
  static int y;
};

int Base::y;

int main(){
  Base b1;
  b1.x =10;  
  b1.y =30; 
 
  Base b2;
  b2.x =30;  
  b2.y =50;  
  cout<<b1.x<<endl;
  cout<<b1.y<<endl;
  cout<<b2.x<<endl;
  cout<<b2.y<<endl;
}
