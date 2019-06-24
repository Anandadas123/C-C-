
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
int main(){
  string word=" ";
  string result=" ";
  string p[10];
  int i=0;
  char str[] ="helloyttyt world";
  int count =0;
  int q = 1;
  while(str[i]!='\0'){
    word+=str[i];
    if(q==5){
      p[count++]=word;
      cout<< word.length() <<endl;
      word=" ";
      q=0;
    }
    if(str[i]==strlen(str)-1){
      p[count]=word;
      cout<< word.length() <<endl;
      break;
    }
   i++;
   q++;
  }
  for(int i=0;i<(sizeof(p)/sizeof(p[0])-1);i++)
    result+=p[i];
  cout<<result<<endl;
}
