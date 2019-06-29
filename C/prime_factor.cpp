#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,j,flag=0,m;
	printf("enter the number");
	scanf("%d",&n);
	printf("prime factor is:");
	for(i=2;i<=n;i++)
	{
		m=i;
		
		for(j=2;j<=m/2;j++)
		{
			flag=0;
			if(m%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			while(n%m==0)
			{
					printf("%d",m);
					n=n/m;
				
			}
		}
		
	}
}
