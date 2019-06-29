#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j,d;
	for(i=1;i<=4;i++)
	{
		d=i+4;
		for(j=5;j>i;j--)
		{
			printf("%d ",d);
			d++;
		}
		printf("\n");
	}	
	
}
