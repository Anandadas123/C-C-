#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10],i,j,n,temp;
	printf("\n enter how the no::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n buble short::");
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>0;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;	
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
