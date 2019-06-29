#include<stdio.h>
#include<conio.h>

int main()
{
struct sp
{
	int row[20];
	int col[20];
	int data[20];
};
	
	int max1=0,max2=0,i,j,k,n;
	struct sp b[20],a[20][20];
	printf("how many no data you want:\n");
	scanf("%d",&n);
	printf("enter the row,column,data:\n");
	printf("i j data\t\n");
	for(i=0;i<n;i++)
	scanf("%d %d %d",&b[i].row[i],&b[i].col[i],&b[i].data[i]);
	for(i=0;i<n;i++)
	{
		if(b[i].row[i]>max1)
		max1=b[i].row[i];
	}
	max1++;
	for(i=0;i<n;i++)
	{
		if(b[i].col[i]>max2)
		max2=b[i].col[i];
	}
	max2++;
	for(k=0;k<n;k++)
	{
		i=b[k].row[k];
		j=b[k].col[k];
		a[i][j]=b[k].data[k];
	}
	printf("\nthe main matrix is::\n");
	for(i=0;i<max1;i++)
	{
		for(j=0;j<max2;j++)
		{
		printf("%d\t",a[i][j]);
	    }
	    printf("\n\n");
	}
	getch();
}
	
	
