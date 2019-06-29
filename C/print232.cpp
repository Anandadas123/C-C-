#include<stdio.h>
#include<conio.h>
int  main()
{
	int i,j,n,d;
	printf("\n enter the line::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		d=i-1;
		for(j=n;j>i;j--)
		printf("   ");
		for(j=1;j<=i;j++)
		{
			printf("  %d",++d);
		}
		d--;
		for(j=1;j<i;j++)
		{
			printf("  %d",d);
			d--;
		}
		printf("\n");
	}
}
