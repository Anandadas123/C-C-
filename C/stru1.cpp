#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
//#include<stdlib.h>
void call()
{
	int i,j,l;
	char c[100],ch;
//	clrscr();
	printf("\n enter the string::");
	scanf("%s",&c);
//	gets(c);
	l=strlen(c);
//	printf("%d\n",l);
	for(i=0;i<l;i++)
	{
		j=i+1;
		printf("%-0.*s\n",j,c);
	}
	j=0;
	for(i=l;i>0;i--)
	{
		{
		j=i-1;
		printf("%-0.*s\n",j,c);
	   }
	   
	}
	fflush(stdin);
	 printf("\n if you want to continue press(y/Y)");
    scanf("%c",&ch);
//   ch=getche();
    if(ch=='y'||ch=='Y')
    call();
}
int main()
{
	call();
}
