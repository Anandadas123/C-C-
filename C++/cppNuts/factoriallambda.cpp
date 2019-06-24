#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
 //int n=5;
  int factorial = [&](int n)->int{
                cout<<n<<endl;
                if(n==0)
                  return 1;
                else
                  return n * factorial(n-1);
              };
 //factorial(5);
cout<<"factorial of "<<"is :"<<factorial(5)<<endl;
}
