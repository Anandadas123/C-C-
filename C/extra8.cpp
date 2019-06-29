#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j,n;
	printf("enter the line::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("* ");
		}
		printf("\n");
   }
}
