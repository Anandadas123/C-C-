#include<stdio.h>
int a,b,c=0;
void partfun();
int main()
{
	auto int a=1;
	partfun();
	a+=1;
	partfun();
	printf("\n %d %d",a,b);
}
void partfun()
{
	register int a=2;
	int b=1;
	a+=++b;
	printf("\n %d %d",a,b);
}
