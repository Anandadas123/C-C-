#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	int i=2,j,count=0,sum=0,flag=0;
	printf("1st 100 prime no addition");
	while(count<100)
	{
		flag=0;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			sum=sum+i;
			printf("%d  ",i);
			count++;
		}
		i++;
	}
	printf("\n total additon of the prime no of %d terms=%d",count,sum);
}
