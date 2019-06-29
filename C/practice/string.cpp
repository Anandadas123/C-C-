#include<stdio.h>
#include<string.h>
int main()
{
	char n[20];
	scanf("%s",n);
	printf("%d",strlen(n));
	for(int i=0;n[i]!='\0';i++)
	printf("%c",n[i]);
}
