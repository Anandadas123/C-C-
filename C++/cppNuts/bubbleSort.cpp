#include<iostream>
using namespace std;
void swap(int *p,int *q){
  int temp =*p;
  *p=*q;
  *q=temp;
}
void bubble_sort(int arr[],int n){
  int i,j,flag;
  for(i=0;i<n-1;i++){
    flag=0;
    for(j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        swap(&arr[j],&arr[j+1]);
        flag=1;
      }
    }
    if(flag==0)
      break;
  }
}
int main(){
  int n,i,p;
  cout<<"Enter the number of Element for array:";
  cin>>n;
  int arr[n];
  cout<<"Enter the " <<n<< " Elements:"<<endl;
  for(i = 0;i<n;i++){
    cin>>p;
    arr[i]=p;
  }
  bubble_sort(arr,n);
  cout<<"sorted arry element is:"<<endl;
  for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
