#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,n,count=0;
	printf("upto which year you want to know counting leepyear::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		count++;
	}
	printf("the total leep year=%d",count);
}
