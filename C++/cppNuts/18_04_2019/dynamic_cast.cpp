#include<iostream>
#include<string.h>
using namespace std;

class Base{
  virtual void print() {cout<<"Base"<<endl;}
};
class Derived1 : public Base{
  void print () {cout<<"Derived1"<<endl;}
};
class Derived2: public Base{
  void print () {cout<<"Derived2"<<endl;}
};
int main(){
  Derived1 d1;
  Base *bp = dynamic_cast<Base*>(&d1);
  Derived1 *dp2 = dynamic_cast<Derived1*>(bp);
  if(dp2 == nullptr)
    cout<< "NULL" <<endl;
  else
    cout<< "NOT NULL" <<endl;
  return 0;
}
