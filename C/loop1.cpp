#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j;
	for(i=1;i<=25;i++)
	{
		if(i==13)
			printf("O ");
		else
			printf("S ");
		if(i%5==0)
			printf("\n");
	}
}
