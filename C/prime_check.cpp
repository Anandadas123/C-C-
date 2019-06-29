#include<stdio.h>
int prime(int,int);
int main()
{
	int n;
	printf("Enter the number");
	scanf("%d",&n);
	int p=prime(n,2);
	if(p==1)
		printf("The number is not prime");
	else
		printf("The number is  prime");
}
int prime(int n,int i)
{
	if(n==i)
		return 0;
	else
	{
		if(n%i==0)
			return 1;
		else
			prime(n,++i);
	}
}
