#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int  main()
{
	char st[20][20],temp[20];
	int i,j,n;
	printf("\n how many no string you enter::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%s",st[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(st[i],st[j])>0)
			{
				strcpy(temp,st[i]);
				strcpy(st[i],st[j]);
				strcpy(st[j],temp);
			}
		}
	}
	printf(" <==assending order list==>\n");
	for(i=0;i<n;i++)
	printf("%s \n",st[i]);
	printf(" <==dessending order list==>\n");
	for(i=n-1;i>=0;i--)
	printf("%s \n",st[i]);
}
