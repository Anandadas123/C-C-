#include<stdio.h>
int main()
{
	int q,a[10],j,i=0,p,m;
	printf("\n enter the no");
	scanf("%d",&p);
		q=m=p;
		a[i++]=q%2;
		q=q/2;
		while(q>0)
		{
			a[i]=q%2;
			q=q/2;
			if(a[i]==1 && a[i-1]==1)
			{
				i=0;
				m++;
				p=m;
				a[i++]=p%2;
				p=p/2;
				q=p;
				continue;
			}
			i++;
		}
		printf("%d\n",m);
		for(j=i-1;j>=0;j--)
		printf("%d ",a[j]);
}
