#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,n;
	printf("\n enter the lines::\n");
	scanf("%d",&n);
	printf("\n the asteric is::\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		printf("*");
		printf("\n");
	}
}
