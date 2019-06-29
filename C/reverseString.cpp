#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i=0,j=0,k=0,l=0;
    char x[14]= "I LOVE CODING";
    char y[14]={'\0'};
    for(i=0;i<=14;i++)
    {
          if(x[i]==' ' || x[i]=='\0')
          {
            for(j=i-1;j>=l;j--)
                y[k++]=x[j];
            y[k++]=' ';
            l=i+1;
          }
    }
    cout<<y<<"\n";
    return 0;
}
