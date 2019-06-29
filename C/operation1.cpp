#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	int i=0,j=0,n,l,line=0,m=0;
	char st[80],word[50],ch,longst[20];
	printf("enter  a sentence::");
    gets(st);
	strcpy(word," ");
	strcpy(longst," ");
	while(i<=strlen(st))
	{
		ch=st[i];
		if(ch==' '||ch=='\t')
		{
			m++;
			word[j]='\0';
			if(strlen(word)>strlen(longst))
			strcpy(longst,word);
			strcpy(word," ");
			j=0;
		}	
		else
		{
			word[j]=ch;
			j++;
		}
		if(ch=='.')
		line++;
		i++;
    }
	printf("\n total character=%d",strlen(st));
	printf("\n total words=%d",m+1);
	printf("\ntotal line=%d",line+1);
	printf("\n longest word =%s",longst);
	
}
