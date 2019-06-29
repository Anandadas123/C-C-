#include<stdio.h>
#include<conio.h>
int main()
{
	int n,key,i,j;
	printf("\n how many you want");
	scanf("%d",&n);
	int a[n];
	printf("\ninsert the element");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>-1 && a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
	printf("\nsorted elements is==>>\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
