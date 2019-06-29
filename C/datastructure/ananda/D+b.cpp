#include<stdio.h>
int fun(int n,int b)
{
	int d=n%b;
	if(n==0)
		return 0;
	else
		fun(n/b,2);
	printf("%d",d);
}
int main()
{
	int n=5;
	//scanf("%d",&n);
	fun(n,2);
}
