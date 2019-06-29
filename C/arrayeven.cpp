#include<stdio.h>
#include<conio.h>
#define SIZE 5
int main()
{
	int a[SIZE],i,j,n;
	for(i=0;i<SIZE;i++)
	{
		printf("\n the element is a[%d]::",i);
		scanf("%d",&a[i]);	
	}
	for(i=0;i<SIZE;i++)
	{
		printf("a[%d]=%d\n",i,a[i]);
	}
	printf("\n the even position no is::\n");
	for(i=0;i<SIZE;i++)
	{
		if(i%2==0)
		{
			printf("%d ",a[i]);
		}
    }
getch();
}
