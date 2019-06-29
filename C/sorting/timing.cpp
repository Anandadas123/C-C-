#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int i,d=0,y=0;
	char str[20];
	printf("%s",__DATE__);
	strcpy(str,__DATE__);
//	printf("%s",str);
	printf("length=%d",strlen(__DATE__));
	for(i=0;i<strlen(__DATE__);i++)
	{
		if(i==4)
		{
			d=0;
			printf("\nday=%d",d);	
		}
		else
			d=(str[4]-48)*10;
		if(i==5)
		{
			int p=d*10+str[i]-48;
			printf("\n%d ",p);
			int q=d+p;
			printf("%d",q);	
		}
		if(i>6&&str[i]!='\0')
		{
			int y=y*10+(str[i]-48);
		}
			
	}
//	printf("day=%d\nyear=%d",d,y);	
}
