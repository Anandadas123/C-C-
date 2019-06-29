#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define ITEMS 10
#define STUDENT 3
int  main()
{
	char st1[20],st[20];
	int i,j;
	printf("\n enter the string::");
	gets(st1);
	for(i=0;i<strlen(st1);i++)
	{
		printf("*");
		st[i]=st1[i];
	}
	printf("\n confirm the string::");
	for(i=0;i<strlen(st1);i++)
	if(st[i]==st1[i])
	{
		printf("\n the password is write");
	}
	else
	printf("\n pasword is not right");
}
