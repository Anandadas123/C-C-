#include<stdio.h>
int main()
{
	long int d1,d2,d3;
	scanf("%ld %ld %ld",&d1,&d2,&d3);
	
	if(d1>d2)
		{
			if((d1+d2+d3)>(2*d1+2*d2))
				printf("%d",2*d1+2*d2);
			else
				printf("%d",d1+d2+d3);
 
		}
		else if(d1<=d2)
		{
			if((d3+d1)<=d2)
			{
				printf("%d",d1+d2+d3);

			}
			else if((d3+d1)>d2)
			{
				if((d1+d2+d3)>(2*d1+2*d2))
					printf("%d",2*d1+2*d2);
				else
					printf("%d",d1+d2+d3);
			}
		}
}
