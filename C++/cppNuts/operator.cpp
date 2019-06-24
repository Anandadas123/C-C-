#include<iostream>
using namespace std;
class Point {
  int x,y;
public:
  Point():x{0},y{0} {}
  Point(int x,int y):x{x},y{y} {cout<<"x"<<x<<endl;cout<<"y="<<y<<endl;}
  Point operator +(const Point & p2) {
    Point p;
    cout<<"x=" << x<<endl;
    p.x=x+p2.x;
    p.y=y+p2.y;
    return p;
  }
  void Print() {
    cout << "x " << x << ", y "<<y <<endl;
  }
};

int main() {
  Point p1(2,3),p2(4,5);
  Point p3= p1+p2;
  p3.Print();
  return 0;
}
