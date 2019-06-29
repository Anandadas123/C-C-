#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	float sum,n,term;
	int count=1;
	printf("enter the value of n::");
	scanf("%f",&n);
	term=1.0/n;
	while(count<=n)
	{
		sum+=term;
		count++;
	}
	printf("sum of the value=%f",sum);
}
