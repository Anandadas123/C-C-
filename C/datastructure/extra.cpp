#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	gets(str);
	int length=strlen(str);
	printf("%s",str);
}
