#include<iostream>
using namespace std;
void swap(int *p,int *q){
  int temp =*p;
  *p=*q;
  *q=temp;
}
void slection_sort(int arr[],int n){
  int i,j,min_id;
  for(i=0;i<n-1;i++){
    min_id =i;
    for(j=i+1;j<n;j++){
      if(arr[j]<arr[min_id]){
        min_id = j;
      }
    }
    swap(&arr[min_id],&arr[i]);
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
  slection_sort(arr,n);
  cout<<"sorted arry element is:"<<endl;
  for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
