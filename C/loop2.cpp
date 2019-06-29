#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j;
	for(i=1;i<=25;i++)
	{
		if(i==6||i==10||i==11||i==15||i==16||i==20||i>=5||(i<=21&&i>=25))
		printf("S");
		else
		printf("  ");
		if(i%5==0)
		printf("\n");
	}
}
