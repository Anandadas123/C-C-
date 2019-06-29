#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	int i=0,j=0,n,l,line=0,m=0;
	char st[80],word[20],ch,longst[20];
	printf("enter  a sentence::");
	//while(st[i++]=getchar()!='\n');
	//printf("%d",i);
	//i--;
	//st[i]='\0';
	gets(st);
	i=0;
	l=strlen(st);
	strcpy(word," ");
	strcpy(longst," ");
	while(i<=l)
	{
		st[i]=ch;
		if(ch==' '||ch=='\t')
		{
		//	m++;
			word[j]='\0';
			if(strlen(word)>strlen(longst))
			strcpy(longst,word);
			strcpy(word," ");
			j=0;
		}	
		else
		{
			word[j]=ch;
		//	m++;
			j++;
		}
		if(ch=='.')
		line++;
		i++;
	}
	i=0;
	while(i<=l)
	{
		if(st[i]==' '||st[i]=='\t')
		m++;
	}
	printf("\n total character=%d",l);
	printf("\n total words=%d",m+1);
	printf("\ntotal line=%d",line);
	printf("\n longest word =%s",longst);
	
}
