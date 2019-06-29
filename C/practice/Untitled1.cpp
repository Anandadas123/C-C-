#include<stdio.h>
extern int p;
int main()
{
   extern int p=10; 
   printf("%d",p);
}



