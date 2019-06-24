#include<iostream>
using namespace std;
class Base{
  int x;
public:
  Base() {}
  Base(int x):x{x} {}
  friend class GetSet;
};
class GetSet {
public:
  void set(Base& obj,int x) {obj.x=x;}
  void get(Base& obj) {return obj.x;}
};


int main(){
  Base obj(10);
  GetSet gs;
  cout<< gs.get(obj) <<endl;
  gs.set(obj,20);
  cout<<gs.get(obj)<<endl;;
 return 0;
}
