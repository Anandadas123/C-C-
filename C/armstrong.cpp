#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,i,p,s,m,r;
	printf("enter the terminate value::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=r=i;
		m=0;
		while(r>0)
		{
			s=r%10;
			r=r/10;
			m=m+s*s*s;
		}
		if(m==p)
		printf("\n %d is armstrong no",p);
	}
}
