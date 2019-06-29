#include<stdio.h>
#include<conio.h>

printarry(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
quick(int a[],int first,int last)
{
	int low=first,high=last;
	int mid=(low+high)/2;
	while(low<high)
	{
		while(a[mid]>a[low])
			low++;
		while(a[mid]<a[high])
			high--;
		if(low<=high)
			{
				int temp;
				temp=a[low];
				a[low]=a[high];
				a[high]=temp;
				low++;
				high--;
			}
	}
	if(first<high)
		quick(a,first,high);
	if(low<last)
		quick(a,low,last);
}
int main()
{
	int a[10],i,n;
	printf("\n enter the no::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n unsorted element::");
	printarry(a,n);
	quick(a,0,n-1);
	printf("\n sorted element::");
	printarray(a,n);
}
