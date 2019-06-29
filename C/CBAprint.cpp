#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	char ch;
	int i,j,n;
	printf("\n enter the line::");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ch='A';
		for(j=1;j<=i;j++)
		{
			printf("%c",ch);
			ch++;
		}
		ch--;
		for(j=n;j>i;j--)
		printf(" ");
		for(j=n;j>i;j--)
		printf(" ");
		printf("\b");
		for(j=1;j<=i;j++)
		{
			printf("%c",ch);
			ch--;
		}
		printf("\n");
		
	}
}
