#include<iostream>
using namespace std;

int main(){
  int n,i,j;
  cout<<"enter the number:"<<endl;
  cin>>n;
  int o=n+(n-1);
  int arr[n][n]={0};
  for(i=0;i<o;i++){
    for(j=0;j<o;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  
}
