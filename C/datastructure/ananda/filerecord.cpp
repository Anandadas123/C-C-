#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int rno,tot,n,i;
	FILE *fp;
	char name[20];
	char choice='y';
	fp=fopen("F:/recor.txt","a+");
//	printf("how many student");
//	scanf("%d",&n);
	while((choice)=='y')
//for(i=0;i<n;i++)
	{
		printf("\n student roll no,name,tot");
		scanf("%d %s %d",&rno,name,&tot);
		fprintf(fp,"%d %s %d",rno,name,tot);
		printf("\n press y-to add more");
		printf("\n any other key to stop");
	choice=getche();
	}
	rewind(fp);
	printf("\n--------------------------------");
	printf(" \n roll no  name  total");
	printf("\n______________________________________");
	while(fp!=EOF)
	{
		fscanf(fp,"%d%s%d",&rno,name,&tot);
		printf("\n%6d \t%-20s \t%6d\n",rno,name,tot);
		//fread
		//	getche();
		fp++;
	}

	fclose(fp);
}
