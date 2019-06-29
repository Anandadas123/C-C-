#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int  main()
{
	char ch;
	//while(ch!=13)
	//{
	//if(ch>=48&&ch<=57)
	//	scanf("%c",ch);
   //printf("%c",ch);
  /* ch=getch();
	while(ch!=13)
	{
		if(isdigit(ch))
		{

		printf("%c",ch);
		}
		if(ch==8)
			printf("\b \b");
		ch=getch();
	}*/
	ch=getch();
	while(ch!=13)
	{
		if(ch==8)
			printf("\b \b");
		else if(ch>=48&&ch<=57)
		{
			printf("%c",ch);
		}

		ch=getch();
	}
  /*ch=getch();
	while(ch!=13)
	{

		if(ch==8)
			printf("\b \b");
		else if((ch>=65&&ch<=122))
		{
			if(ch<=90||ch>=97)
			printf("%c",ch);
		}
		ch=getch();
	}*/

}
