#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,p=1;
	printf("\n enter the value for factorial::");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		p=p*i;
	}
	printf("%d factorial=%d",n,p);
}
