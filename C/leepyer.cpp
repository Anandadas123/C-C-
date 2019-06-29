#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,p,n,count=0;
	printf("enter the terminate year::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		{
		printf("\n %d year is leep year",i);
		count++;
	   }
	}
	printf("\n until %d year total leep years=%d",n,count);
}
