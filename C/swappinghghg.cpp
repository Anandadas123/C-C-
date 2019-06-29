#include<stdio.h>
#include<conio.h>
//void call(int*,int*);
int main()
{
	int a=10,b=20;
//	call(&a,&b);
int *p,*q;
p=&a;
q=&b;
*p=*p+*q;
	*q=*p-*q;
	*p=*p-*q;
	printf("a=%d,b=%d",a,b);
}
/*void call(int *p,int*q)
{
	*p=*p+*q;
	*q=*p-*q;
	*p=*p-*q;
}*/
	
