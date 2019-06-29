#include<stdio.h>
#include<conio.h>
#define SIZE 10
int i,arr[SIZE],m,p,n;
void insert()
{
	printf("enter the position you insert");
    scanf("%d",&m);
	printf("enter the data you insert");
	scanf("%d",&p);
	if(n==SIZE)
		printf("the arry is full");
	else
	{
	for(i=n-1;i>=m-1;i--)
		arr[i+1]=arr[i];
	arr[i+1]=p;
		printf("the no are");
	for(i=0;i<n+1;i++)
		printf("\t%d",arr[i]);
	}
}
void delet()
{
	int q;
    printf("enter the position you delet");
	scanf("%d",&q);
	printf("enter the data you delet");
	scanf("%d",&p);
	if(n==SIZE)
		printf("the arry is full");
	else
	{
	for(i=q-1;i<=n-1;i++)
		arr[i]=arr[i+1];
		printf("the no are");
	for(i=0;i<n-1;i++)
		printf("\t%d",arr[i]);
	}
}
int main()
{
	int ch;
	printf("how many data you enter");
	scanf("%d",&n);
	printf("enter the no:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	while(1)
	{
		printf("\n 1.insert at position\n");
		printf("\n 2.delet at position\n");
		printf("\n 3. disply\n");
		printf("\n 0.exit\n");
		printf("\n enter your choice");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					insert();
					break;
				case 2:
					delet();
					
			}
	}
}


