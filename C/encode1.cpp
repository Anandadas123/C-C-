#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	
//	char str[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};	
	int i,j;
	char  name[15],str1[26]={'m','n','k','g','h','d','t','a','b','w','v','u','p','r','q','c','z','j','x','i','e','y','f','l','o','s'};
	printf("enter a string");
	gets(name);
	for(i=0;i<strlen(name);i++)
	{
		j=name[i]-97;
        printf("%c",str1[j]);
    }
}
