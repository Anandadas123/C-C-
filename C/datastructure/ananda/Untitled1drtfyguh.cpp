#include<stdio.h>
#include<conio.h>
int main()
{
	static int a[5][6];
	struct arr
	{
		int row,column,data;//,a[5][6];
	};
	struct arr s;
	int b[30],c[30],d[30],n,i,j,k;
	printf("HOW MANY NUMBER DO YOU WANT:\n\t");
	scanf("%d",&n);
	printf("\n\ti j k\n");
	for(k=0;k<n;k++)
	{
		printf("\n\t");
		scanf("%d%d%d",&b[k],&c[k],&d[k]);
	}
	for(k=0;k<n;k++)
	{
		for(i=b[k];i<5;i++)
		{
			for(j=c[k];j<6;j++)
			{
				a[i][j]=d[k];
				break;
			}
			break;
		}
	}
	printf("\nTHE ORIGINAL MATRIX IS:\n\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n\n\n");
	}
	getch();
}

