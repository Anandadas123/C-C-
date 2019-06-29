#include<stdio.h>
#include<conio.h>
int main()
{
	int r,c;
	printf("ente the order of matrix(row colume)::");
	scanf("%d%d",&r,&c);
	int a[r][c],i,j,det,t1,t2,p=-1,d[r/2][c/2],q;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<r;i+=2)
	{	
		p++;
		q=0;
		for(j=0;j<c;j+=2)
		{
			det=0;
			t1=a[i][j]*a[i+1][j+1];
			t2=a[i+1][j]*a[i][j+1];
			det=t1-t2;
			d[p][q++]=det;
	    }
	}
	printf("\n matrix is\n");
	for(i=0;i<=p;i++)
	{
	  	for(j=0;j<q;j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
}
