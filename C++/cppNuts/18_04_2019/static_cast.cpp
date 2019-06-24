#include<iostream>
#include<string.h>
using namespace std;

class Int {
  int x;
public:
  Int(int x=0):x{x}{
    cout<<"conversion constructor"<<endl;
  }
  operator string () {
    cout<<"conversion operator"<<endl;
    return to_string(x);
  }
};

int main(){
  Int obj(3);

  string str1 = obj;
  obj = 20;

  string str2 = static_cast<string>(obj);
  obj = static_cast<Int>(30);
}
