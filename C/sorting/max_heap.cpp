#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void build_max_heap(int a[])
{
    float d=1.5;
	printf("%d",(int)floor(d));
}
int main()
{
	int a[10],i,n;
	printf("\n enter the no::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n unsorted element::");
	build_max_heap(a);
}
