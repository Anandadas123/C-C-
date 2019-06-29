#include<stdio.h>
#include<conio.h>
int reverse(int );
int main()
{
	int n;
	printf("enter your number:");
	scanf("%d",&n);
	reverse(n);
}
int reverse(int n)
{
	int rem;
	if(n==0)
		return 0;
	else
	{
		rem=n%10;
		printf("%d",rem);
		n=n/10;
		reverse(n);
		
	}
}
