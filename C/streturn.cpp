#include<stdio.h>
#include<conio.h>
#include<string.h>
char call();
char st1[20],ch;
int i=0;
int  main()
{

printf(" enter the string::");
call();
printf("\n%s",st1);
}

char call()
{
	while((ch=getch())!=13)
	{
		if(ch!=8)
		{
			st1[i++]=ch;
			printf("%c",ch);
    	}
	}
st1[i]='\0';
return *st1;
}
