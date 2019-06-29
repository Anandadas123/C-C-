#include<stdio.h>
//#include<conio.h>
#include<math.h>
int  main()
{
	char ch;
	int i,j,n;
	printf("\n enter the line::");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		ch='A';
		for(j=n;j>=i;j--)
		{
			printf("%c",ch);
			ch++;
		}
		ch--;
		for(j=n;j>(n-i+1);j--)
		{
		printf("  ");
		}
		printf("\b");
		for(j=n;j>=i;j--)
		{
			printf("%c",ch);
			ch--;
		}
		printf("\n");
	}
	printf("_______________________________________________");
}
