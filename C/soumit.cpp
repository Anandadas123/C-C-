#include<stdio.h>
int main()
{
	int i;
	for(i=1;i<=15;i++)
	{
		printf("* ");
		if(i%5==0)
			printf("\n");
			
	}
	for(i=1;i<=4;i++)
	{
			printf("* ");
			if(i%2==0)
				printf("\n");
	
	}
	for(i=1;i<=15;i++)
	{
		printf("* ");
		if(i%5==0)
			printf("\n");
	}
	for(i=1;i<=10;i++)
	{
		if(i==4||i==5||i==9||i==10)
			printf("* ");
		else
			printf("  ");
		if(i%5==0)
			printf("\n");
	}
	for(i=1;i<=15;i++)
	{
		printf("* ");
		if(i%5==0)
			printf("\n");
	}
	
}
