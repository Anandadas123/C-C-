#include<stdio.h>
#include<conio.h>
#define SIZE 4
void insert();
void delet();
void traverse();
int queue[SIZE],front=0,rear=0;
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
	if(front<rear)
	{
		item=queue[front];
		printf("the delet item=%d",item);
		front++;
    }
    else
		printf("queue is underflow"); 	
}
void traverse()
{
	int i;
	for(i=front;i<rear;i++)
		printf("%d\t",queue[i]);
	if(front==rear)
		printf("queue is empty");
}
