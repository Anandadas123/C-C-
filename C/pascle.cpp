#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j,n,m;
	printf("enter the line::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=n;j>i;j--)
		printf("  ");
		for(j=0;j<=i;j++)
		{
			if(i==0||j==0)
			m=1;
			else
			m=(m*(i-j+1)/j);
			printf("%d   ",m);
		}
		printf("\n");
	}
}
