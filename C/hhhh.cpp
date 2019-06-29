#include<stdio.h>
#include<conio.h>
int fun(int n)
{   
	if(n==0)
	return 0;
	int d=n%2;
	fun(n/2);
	printf("%d ",d);
}
int main()
{
	
	int n=50;
	fun(n);
}
