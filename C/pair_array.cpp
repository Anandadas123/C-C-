#include<stdio.h>
#include<conio.h>
int  main()
{
	int i,j,a[10],n,x,flag;
	printf("\n how many no you enter ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter the value which add of pair is equal");
	scanf("%d",&x);
	printf("\n pair of the element is");
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]+a[j]==x)
			{
				printf("(%d,%d) ",a[i],a[j]);
				flag=1;
			}
		}	
	}
	if(flag!=1)
	    printf("   not present");
}
