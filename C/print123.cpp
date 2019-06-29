#include<stdio.h>
//#include<conio.h>
int main()
{
	int i,j,n,d,a[20][20],sum,s=0;
	printf("enter the line::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		d=i+1;
		for(j=0;j<n;j++)
		{
			if(d<=n)
			{
				printf("%d\t",d);
				a[i][j]=d;
				s=s+d;
		    }
			else
			{
				printf("%d\t",d%n);
				a[i][j]=d%n;
				s=s+d%n;
			}
	
			d++;	
		}
		printf("  %d",s);
		s=0;
		printf("\n\n");
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			s=s+a[j][i];
		}
		printf("%d\t",s);
		s=0;
	}
        printf("\n");
}
