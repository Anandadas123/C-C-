#include<stdio.h>
#include<conio.h>
int count=0,s1=0,s2=0;
int test(long int);
int main()
{
	long int n;
	printf("enter number:");
	scanf("%lu",&n);
	test(n);
}
int test(long int n)
{
	int rem,diff;
	rem=n%10;
	n=n/10;
	count++;
	if(count%2!=0)
		s1=s1+rem;
	else
		s2=s2+rem;
	diff=s1-s2;
	if(n>0)
		test(n);
	else if(diff==0)
		printf("divisable by 11");
	else
		printf("not divisable by 11");
}
