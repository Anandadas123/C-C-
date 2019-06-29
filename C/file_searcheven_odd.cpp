#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	FILE *file1,*file2,*file3;
	char ch;
	file1=fopen("F:\\test1.txt","r");
	file2=fopen("F:\\test2.txt","w");
	file3=fopen("F:\\test3.txt","w");
	while((ch=fgetc(file1))!=EOF)
	{
		if(ch%2==0)
		    fputc(ch,file2);
		else
			fputc(ch,file3);
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
}
