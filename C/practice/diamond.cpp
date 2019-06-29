#include<stdio.h>
int main()
{
	int n,i,j;
	printf("How many Line you want to print\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=(n-i);j++)
		printf(" ");
		for(j=1;j<=i;j++)
		printf("* ");
		printf("\n");
	}
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<=i;j++)
		printf(" ");
		for(j=1;j<=(n-1-i);j++)
		printf("* ");
		printf("\n");
	}
}
