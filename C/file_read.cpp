#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *fp;
	char ch;
	//fp=fopen("F:\\file.txt","r");
	fp=fopen("D:\\txt","r");
	while((ch=fgetc(fp))!=EOF)
		fputc(ch,fp);   
	//fclose(fp);
	fclose(fp);
}
