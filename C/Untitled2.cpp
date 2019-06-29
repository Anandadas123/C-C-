#include<stdio.h>
#include<conio.h>
int main()
{
	int a[]={4,7,-1,0,-3,1};
	int max=a[0];
	int min=a[0];
	int len=sizeof(a)/sizeof(int);
	//printf("%d",len);
	for(int i=1;i<len;i++)
	{
		if(max<a[i])
		max=a[i];
		if(min>a[i])
		min=a[i];
		
	}
	printf("maximum value=%d",max);
	printf("maximum value=%d",min);
}
