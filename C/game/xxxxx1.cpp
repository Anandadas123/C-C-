#include<stdio.h>
int main()
{
	int a[10][10],i,j;
	a[0][8]=1;
	a[1][6]=1;
	a[2][2]=1;
	a[4][2]=1;
	a[4][5]=1;
	a[5][4]=1;
	a[7][1]=1;
	a[7][2]=1;
	a[7][7]=1;
	a[8][7]=1;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("|");
			if(a[i][j]==1)
				printf("B");
			else 
				printf(" ");
			if(j==9)
			{
				printf("");
				printf("|");
			}
		}
		printf("\n");
	}
}
