#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
int main(){
  string word=" ";
  string p[2];
  int i=0;
  char str[] ="hello world";
  int count =0;
  while(str[i]!='\0'){
    word+=str[i];
    if(str[i]==' '|| i ==strlen(str)-1){
      cout<<word<<endl;
      p[count++]=word;
      word=" ";
    }
   i++;
  }
  for(int i=(sizeof(p)/sizeof(p[0])-1);i>=0;i--)
    cout<<p[i];
}
