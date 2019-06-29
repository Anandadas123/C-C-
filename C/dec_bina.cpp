#include<stdio.h>
int fun(int,int);
int main()
{
	int n;
	printf("\n Enter decimal no::");
	scanf("%d",&n);
	printf("\n Binary form::");
	fun(n,2);
	printf("\n Octal from::");
	fun(n,8);
	printf("\n Hexadicimal from::");
	fun(n,16);
	
}
int fun(int n,int base)
{
	int d=n%base;
	if(n==0)
		return 0;
	fun(n/base,base);
	(d>9)?(printf("%c ",'A'+d-10)):printf("%d ",d);
	
		
}
