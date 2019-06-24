#include<iostream>
#include<string.h>
using namespace std;

class Base {
	int b_var;
public:
	virtual void fun(){cout<< "Base fun"<<endl;}
};

class Derived : public Base{
	int d_var;
public:
	void fun() override {cout<< "Derived fun"<<endl;}
};

int main(){

 Base *b = new Derived();
 b->fun();

  return 0;
}
