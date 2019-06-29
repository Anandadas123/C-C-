#include<stdio.h>
int main()
{
	int n,i,d,num=0,p;
	printf("\n enter the no::");
	scanf("%d",&n);
	while(n>0)
	{
		d=n%10;
		num=num*10+d;
		n=n/10;
	}
	while(num>0)
	{
		p=num;
		while(p>0)
		{
			i=p%10;
			printf("%d ",i);
			p=p/10;
		}
		printf("\n");
		num=num/10;
	}
}
