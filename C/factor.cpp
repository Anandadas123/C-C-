#include<stdio.h>
#include<conio.h>
long fact(int n);
int n;
int main()
{
	float num,deno,i;
	printf("enter the terminal value::");
	scanf("%d",&n);
	deno= fact( n);
	printf("%f",deno);
	num=1.0;
	i=num/deno;
	printf("the sumesion value i=%f",i);
}
	long fact(int n)
	{
		if(n==0)
		return 1;
		else
		return (n*(fact(n-1)));
	}	
