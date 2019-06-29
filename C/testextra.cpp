#include<stdio.h>
/*int *fun(int *p, int n);
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},n,*ptr;
	n=5;
	ptr=fun(a,n);
	printf("a=%p,ptr=%p,*ptr=%d",a,ptr,*ptr);
}
int *fun(int *p,int n)
{
	p=p+n;
	return p;
}*/
//void func(val[ ]);
int main()
{
	int a[5]={1,2,3,4,5},i,j,sum=0;
	//func(a);
	for(i=0;i<5;i++)
	{
		a[i]=a[i]*a[i];
		sum=sum+a[i];
	}
	printf("\n the squre of array");
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
}
/*void func(val[ ])
{
	int sum=0,i;
	for(i=0;i<5;i++)
	{
		a[i]=a[i]*a[i];
		sum=sum+a[i];	
	}
	printf("\n the sum of the squre");
}*/
