#include<stdio.h>
#include<conio.h>
int main()
{
	int pow,n,a[30],i=1,p,q,r;
	printf("\n enter the value of num and its power\n");
	scanf("%d%d",&n,&pow);
	n=n%100;
	q=a[0]=n;
	printf("%d ",a[0]);
	while(1)
	{
		a[i]=(q*n)%100;
		for(p=0;p<i;p++)
		{
			for(r=p+1;r<i;r++)
			{
				if(a[p]==a[r])
					return 0;
			}
		}
		printf("%d ",a[i]);
		q=a[i];
		i++;
	}
}

