#include<stdio.h>
#include<conio.h>
#include<math.h>
int  main()
{
	int a[4][4]={0,2,0,0,0,0,2,0,0,0,0,3,0,0,0,2},i,j,k;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0)
			{
				for(k=1;k<4;k++)
				{
					if(a[i][j]!=a[0][k]&&a[i][j]!=a[k][0]);
					   printf("%d",a[i][j]);
				}
			}
		}
	}
/*	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
	
	printf("%d ",a[i][j]);
	printf("\n");
		}
	
}*/
}
