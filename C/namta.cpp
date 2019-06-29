#include<stdio.h>
//#include<conio.h>
int call()
{
	int i,j,n;
	char ch;
	printf("\nenter the no::");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	   printf("%d\t",n);
	printf("\n");
	for(i=1;i<=10;i++)
     	printf("%d\t",i);
	printf("\n");
	for(i=1;i<=10;i++)
	{
		j=n*i;
		printf("%d\t",j);
	}
	//printf("\nare you want to contiue::(y/Y)");
	//ch=getch();
	//if(ch=='y'||ch=='Y')
	//call();
	//else
	return 0;
}
int main()
{
	call();
}
