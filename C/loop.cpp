#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,j,n,d;
	printf("enter the line::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		d=i;
		for(j=n;j>i+1;j--)
		printf("  ");
		for(j=0;j<=i;j++)
		{
		printf("%d ",d);
		d--;
	    }
	    d+=2;
	    for(j=0;j<i;j++)
	    {
	    	printf("%d ",d);
	    	d++;
	    }
	    printf("\n");
		
	}
}
