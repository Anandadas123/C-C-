
#include<iostream>
using namespace std;
class Test {
public:
  void fun(int x) {cout<<"integer"<<endl;}
  void fun (double x) {cout<<"double"<<endl;}
};

int main(){
  Test t1;
  t1.fun(10);
  t1.fun(10.5);
 return 0;
}
