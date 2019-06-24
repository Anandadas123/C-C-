#include<iostream>
using namespace std;
int fun(){
  static int num =9;
  num--;
}
int main() {
  for(fun();fun();fun())
   cout<<fun();
}
