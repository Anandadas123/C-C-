#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *p;
	char ch;
	p=fopen("D:\\ftkykyuyu.txt","w");
	
	while((ch=getchar())!=EOF)
	{
		putc(ch,p);
		//printf("%c",ch);	
	}
	fclose(p);
}
