#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j,n,d,a[20][20],sum;
	printf("enter the line::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		d=i;
		for(j=n;j>=i;j--)
		{
			printf("%d\t",d);
			d++;
		}
		d-=4;
		for(j=1;j<i;j++)
		{
			printf("%d\t",d);
			d++;
		}
		printf("\n");
	}
}
