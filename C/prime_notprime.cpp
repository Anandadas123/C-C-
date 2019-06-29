#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,p,flag,m,count=0,avg,d=0;
	printf("enter the terminate value::");
	scanf("%d",&n);
	for(p=2;p<=n;p++)
	{
		m=p;
		for(i=2;i<=p/2;i++)
		{
			flag=0;
			if(p%i==0)
			{
				printf("\n %d is not prime",m);
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			count++;
			d=d+m;
			printf("\n %d is prime",m);
		}
	}
	printf("\n total prime no addition=%d ",d);
	printf("\n avg of prime no=%f",d/(float)count);
	printf("\ntotal prime no=%d",count);
}
