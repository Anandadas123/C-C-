#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	int i,j,n,t;
	float median,a[10];
	printf("how many element you want");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%f",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]<=a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;	
			}
			else
			continue;
		}
	}
	if(n%2==0)
		median=(a[n/2+1]);
	else
		median=a[n/2];
	for(i=0;i<n;i++)
	printf("%f ",a[i]);
	printf("median=%f",median);
}
