#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int  main()
{
	int i,j,l;
	char c[ ]="program";
	l=strlen(c);
	for(i=0;i<l;i++)
	{
		j=i+1;
		printf("%-7.*s\n",j,c);
	}
	for(i=l;i>=0;i--)
	{
		j=i+1;
		printf("%-7.*s\n",j,c);
	}
}
