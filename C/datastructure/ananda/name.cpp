#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char st[30];
	int i,ln,count=0;
	printf("enter the strinng(maximam 3 words):");
	gets(st);
	ln=strlen(st);
	printf("\n the 1st name is:");
	for(i=0;i<ln;i++)
	{
		if(st[i]==' ')
		count++;
	}
	if(count==1||count==2)
	{
		for(i=0;st[i]!=' ';i++)
		{
			printf("%c",st[i]);
		}
    }	
if(count==0)
	{
	for(i=0;st[i]!='\0';i++)
	{
			{
			printf("%c",st[i]);
		    }
		}
}	
	if(count==2)
		{
		printf("\nthe midil name is:");
			for(i=i+1;st[i]!=' ';i++)
		{
				{
			printf("%c",st[i]);
		    	}
		}
    }
    if(count==1||count==2)
    {
		printf("\nthe last name is:");
			for(i=i+1;st[i]!='\0';i++)	
			{
			printf("%c",st[i]);
	        }
    }
}
