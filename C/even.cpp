#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j,n,count=0;
	printf("upto which no you want to know the even no::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
		printf("%d ",i);
		count++;
	    }
	}
	printf("\n count=%d",count);
}
