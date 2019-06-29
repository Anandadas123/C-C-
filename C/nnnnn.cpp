#include<stdio.h>
#include<conio.h>
void call()
{
	unsigned int n,i,j;
	char ch;
	printf("enter the number   ");
	scanf("%d",&n);
for(i=1;i<=10;i++)
	{
		j=n*i;
		printf("\n%d * %d = %d",n,i,j);
	}
fflush(stdin);
printf(" are you want to compute again??(y/n)");
scanf("%c",&ch);
if (ch=='y'||ch=='Y')
call();

}
int main()
{

	call();
	
	}
