#include<stdio.h>
#include<conio.h>
int main()
{
	int num,i,j;
	printf("\n enter the num");
	scanf("%d",&num);
	for(i=1;i<num/2;i++)
	{
		for(j=i;j<num;j++)
		{
			if(i*j==num)
			{
				printf("\n %d*%d=%d",j,i,num);
			}
		}
	}
}
