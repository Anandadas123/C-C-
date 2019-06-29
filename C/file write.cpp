#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *fp;
	char ch;
	int p,big=0;
	fp=fopen("F:\\fghj.txt","r");
	while((p=getw(fp))!=EOF)
	{
		if(p>big)
		big=p;
	}
	fclose(fp);
	printf("\n bigist no=%d",big);
}
