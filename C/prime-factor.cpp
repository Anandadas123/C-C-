#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	int n,i=2;
	printf("\n enter the prime factor of number");
	scanf("%d",&n);
	while(n>0)
	{
		while(n%i==0)
		{
			n/=i;
			printf("%d ",i);
		}
		i++;
	}
}
