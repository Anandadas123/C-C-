#include<stdio.h>
int main()
{
	char a[5];
	a[4]='2';
	a[4]=(((a[4]-48)+1)+48);
	printf("%c",a[4]);
}
