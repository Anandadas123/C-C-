#include<stdio.h>
#include<conio.h>
#define SIZE 4
void insert();
void delet();
void traverse();
int queue[SIZE],rear=0,i;
int main()
{
	int choice;
	while(1)
	{
		printf("\n 1.insert");
		printf("\n 2.delet");
		printf("\n 3.TRAVERS");
		printf("\n 4.EXIT");
		printf("\nENTER YOUR CHOICE");
			scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
				break;
			case 2:
			    delet();
				break;
			case 3:
				traverse();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("\n wrong choice");
		}
    }
    getch();
}
void insert()
{

	int item;


	if(rear<SIZE)
	{
		printf("\nenter the data");
		scanf("%d",&item);
		queue[rear]=item;
		rear=rear+1;
	}
	else
		printf("queue is overflow");
}
void delet()
{
    int item;
	if(rear<0)
	printf("queue is underflow");
	else
	{
	    printf("delet data=%d",queue[0]));
		for(i=0;i<rear;i++)
		queue[i]=queue[i+1];
		rear--;
    }

}
void traverse()
{
	int i;
	if(rear<0)
		printf("queue is empty");
	else
	{
	for(i=0;i<rear;i++)
		printf("%d\t",queue[i]);
    }
}
