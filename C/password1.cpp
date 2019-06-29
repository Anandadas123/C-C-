#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int  main()
{

char  ch,st1[20],st2[20];
int i=0,j=0,flag=0;
printf(" enter the password::\n");
while((ch=getch())!=13)
{
	if(ch!=8)
	{
		st1[i++]=ch;
		printf("*");
    }
    
	else	
    {
		printf("\b \b");         
				i--;
	}
}
st1[i]='\0';
	printf("\n re_enter the password::\n");
while((ch=getch())!=13)
{
	if(ch==8)
	{
		printf("\b \b");
		j--;
	}
	else
	{
		st2[j++]=ch;
		printf("*");
    }
}
st2[j]='\0';
for(j=0;j<i;j++)
{
	if(strcmp(st1,st2)==0)
		flag=0;
	else
		flag=1;
}
if(flag==0)
	printf("\n password is Right");
else
	printf("\n password is wrong");
}
