#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,count,n,temp=0,x,y,p,q,r,k,s;
	printf("\n enter the terminate value");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	temp=0;
		for(j=1;j*j<=n;j++)
		{
			for(k=j+1;k*k<=n;k++)
			{
				//printf("\n%d",k);
				s=pow(j,3)+pow(k,3);
				if(s==i)
				{
					temp++;
					if(temp==1)
					{
						x=j;
						y=k;
						r=i;
					}
					if(temp==2)
					{
						if(i==r)
						{
							p=j;
							q=k;
							printf("\n num are=%d  %d and  %d   %d",x,y,p,q);
							printf("  the ramanujam no=%d",i);
						}
					}
				}
			}
		}
	}
}
