#include<iostream>
#include<stdlib.h>

using namespace std;

void findConsicutive(int N){
  int start = 1, end =(N+1)/2;
  int sum=0;
  while(start<end){
    sum=0;
    for(int d=start;d<=end;d++){
      sum+=d;
      if(sum==N){
        for(int p=start;p<=d;p++){
          cout<< p <<" ";
        }
          cout<<endl;
      }
      if(sum>N)
        break;
    }
    start++; 
  }
}
int main(){
  int n;
  cout<<"Enter the Number which executed number's are all: "<<endl;
  cin>>n;
  findConsicutive(n);

}
