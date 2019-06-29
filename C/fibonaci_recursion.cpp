#include<stdio.h>
//#include<conio.h>
int fibo(int);
int main()
{
	int i,n;
	printf("enter how many terms???");
	scanf("%d",&n);
	printf("febonaci seriera is:\n");
	printf("0 ");
	for(i=0;i<n-1;i++)
		printf(" %d",fibo(i));
        printf("\n");
}
int fibo(int i)
{
	if(i==0||i==1)
	return 1;
	else
	return(fibo(i-1)+fibo(i-2));
}
