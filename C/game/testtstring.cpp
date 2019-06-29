#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int p=40,i;
	char a[5];
	a[0]=(p%10);
	p=p/10;
	a[1]=(p+48);
	a[2]='\0';
	for(i=0;i<2;i++)
		printf("%c",a[i]);
	
	
}
