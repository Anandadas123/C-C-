#include<stdio.h>
#include<conio.h>
#include<string.h>
//#include<math.h>
int  main()
{
	int i,j,count=0;
	char st[20],ch;
	printf("enter the string::");
	gets(st);
	printf("\n which character you search::");
	scanf("%c",&ch);
	for(i=0;i<strlen(st);i++)
	{
		if(ch==st[i])
		count++;
	}
	printf("the character %c is total count =%d",ch,count);
}
