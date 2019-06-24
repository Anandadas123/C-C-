#include<iostream>
using namespace std;
template <typename T>
T display(T arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<"\t";
  }
}

template <typename T>
void sort(T arr, int n){
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(arr[i]>arr[j]){
        swap(arr[i],arr[j]);
      }
    }
  }
}

template <typename T>
void swap(T &val1,T &val2){
  T temp = val1;
  val1= val2;
  val2=temp;
}

int main(){
  cout<<"\n============>integer Array:\n";
  int arr[6]={4,5,2,1,8,2};
  display(arr,6);
  sort(arr,5);
  cout<<"\n============> sort of integer Array:\n";
  display(arr,5);
  cout<<"\n============>float Array:\n";
  float arr1[6] = {5.2,5.1,2.7,1.5,2.5,2.3};
  display(arr1,6);
  sort(arr1,6);
  cout<<"\n============> sort of float Array:\n";
  display(arr1,6);

  return 0;
}
