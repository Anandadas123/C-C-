#include<stdio.h>
#include<conio.h>
#include<math.h>
int  main()
{
	int i,j,n,d;
	printf("enter the line::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		d=i;
		for(j=1;j<=i;j++)
		{
			if(d%2==0)
				printf("0");
			else
				printf("1");
				d++;
		}
		printf("\n");
	}
}
