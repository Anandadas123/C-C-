#include<stdio.h>
void count1(int n)
{
	static int d=1;
	
	printf("%d ",n);
	printf("%d ",d);
	d++;
	if(n>1)
	count1(n-1);
	printf("%d ",d);
	
	
}
int main()
{
 count1(3);	
}
