#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char str[20]="123456789";
	int a[20],i,j,p;
	int len=strlen(str);
	for(i=0;i<len;i++)
		a[i]=(str[i]-48);
	for(i=0;i<5;i++)
	{
		p=i;
		for(j=5;j>i;j--)
			printf("  ");
		for(j=0;j<=i;j++)
		{
			printf(" %d",a[p++]);
		}
		p=p-2;
		for(j=0;j<i;j++)
		{
			printf(" %d",a[p--]);

		}
		printf("\n");
	}
}
