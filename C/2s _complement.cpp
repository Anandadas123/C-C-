#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	int i,j,n,len,l;
	char a[100],a1[100];
	printf("enter the binary no:");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='0'&&a[i]!='1')
		{
			printf("\n incorect binary from");
			return 0;
		}
	}
	len=strlen(a);
	printf("\n 1s complement=");
	for(l=0;l<len;l++)
	{
		if(a[l]=='0')
		{
			a1[l]='1';
			printf("%c",a1[l]);
     	}
		else
	    {
			a1[l]='0';
			printf("%c",a1[l]);
     	}

    }
    printf("\n");
	for(i=len-1;a[i]!='1';i--);
	for(j=i-1;j>=0;j--)
	{
		if(a[j]=='1')
			a[j]='0';
		else
			a[j]='1';
	}

	printf("\n 2s complement=%s ",a);

}
