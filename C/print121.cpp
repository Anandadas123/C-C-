#include<stdio.h>
//#include<conio.h>
#include<math.h>
int main()
{
	int i,j,n,d,a[20][20],sum,s=0;
	for(i=0;i<4;i++)
	{
		d=i+1;
		for(j=0;j<4;j++)
		{
			if(d<5)
			{
			printf("%d\t",d);
			a[i][j]=d;
			s=s+d;
		    }
			else
			{
				printf("%d\t",d%4);
				a[i][j]=d%4;
				s=s+d%4;
			}
			d++;	
		}
		printf("=>%d",s);
		s=0;
		printf("\n");
	}
	printf("\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			s=s+a[j][i];
		}
		printf("%d\t",s);
		s=0;
	}
}