#include<stdio.h>
#include<conio.h>
int swap(int,int);
int main()
{
	int a=10,b=15;
	printf("before function called a=%d ,b=%d\n",a,b);
	swap(a,b);
	printf("after function called a=%d ,b=%d\n",a,b);
}
int swap(int a,int b)
{
	int t;
	t=a;
	a=b;
	b=t;
	printf("a=%d  b=%d\n",a,b);
}
