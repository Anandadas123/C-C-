#include<iostream>

using namespace std;

int compare(const void *p, const void *q) {
  int l = *(const int*)p;
  int r = *(const int*)q;
  return l>r;
}
int main(){

  int Arr[5] = {3,2,1,5,2};
  int ArrSize =sizeof(Arr)/sizeof(Arr[0]);
  int elementSize =sizeof(Arr[0]);
  qsort(Arr,ArrSize,elementSize,compare);
  for(int i=0;i<ArrSize;i++){
    printf("%d\n", Arr[i]);
  }
}