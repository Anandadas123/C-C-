
//*****************prime factorial*************************//

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,n,p,flag=0,m;
	printf("enter the value value::");
	scanf("%d",&n);
	printf("\n prime factorition::");
	for(p=2;p<=10000;p++)
	{
		m=p;
		for(i=2;i<=p/2;i++)
		{
			flag=0;
			if(p%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			while(n%m==0)
			{
				printf("%d ",m);
	  	 		n=n/m;
			}
	    }
	}
}
