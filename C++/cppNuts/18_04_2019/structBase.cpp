#include<iostream>
#include<string.h>
using namespace std;

class classBase {
	int _bar;

};

struct structBase{
	int _bar;
};

int main(){

  classBase cb;
  structBase sb;
  sb._bar=10;

  return 0;
}
