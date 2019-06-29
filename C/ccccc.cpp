#include<stdio.h>
int main()
{
	int a=11101,b=11011,c;
	bit_pattern(a);
	a=a<<2;
	printf("%d",a);
	bit_pattern(a);
}
