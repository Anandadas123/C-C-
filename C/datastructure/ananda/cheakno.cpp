#include<stdio.h>
#include<conio.h>
#define SIZE 10
int arr[SIZE];
int n,i,ch,flag=0;
void check(int ch)
{
	for(i=0;i<n;i++)
	{
		if(arr[i]==ch)
		{
			printf("\nthe no: %d is found and %d position",ch,i+1);
			flag=1;
		}
	    continue;
	}
	if(flag==0)
	printf("\nthe no: %d is not found",ch);
}
int main()
{
	printf("\nhow many no you want?");
	scanf("%d",&n);
	printf("enter the no:");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("enter your find the no:");
	scanf("%d",&ch);
	check(ch);
	getch();
}
