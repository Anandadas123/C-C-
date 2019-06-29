#include<stdio.h>
int main()
{
	int p,a[20],i=0,j;
	printf("\n how many no you want to");
	scanf("%d",&p);
	//printf("\n enter two numbers");

	while(1)
	{
	a[i++]=p%2;
	p=p/2;
	while(p!=0)
	{
		a[i]=p%2;
		 p=p/2;
		 if(a[i]==1 && a[i-1]==1)
		 {
		 	p++;
		 	i=0;
			break;
		 }
		 i++;
		 
	}
	if(p==0)
	break;
	}
	for(j=i;j>=0;j--)
	printf("%d ",a[j]);
}

