#include<stdio.h>
#include<conio.h>
#define SIZE 5
void cqinsert();
void cqdelet();
void cqtraverse();
int cq[SIZE],front=0,rear=0;
int main()
{
	int choice;
	while(1)
	{
		printf("\n 1.cqinsert");
		printf("\n 2.cqdelet");
		printf("\n 3.CQTRAVERS");
		printf("\n 4.EXIT");
		printf("\nENTER YOUR CHOICE");
			scanf("%d",&choice);
		switch(choice)
		{
			case 1:cqinsert();
				break;
			case 2:
			    cqdelet();
				break;
			case 3:
				cqtraverse();
				break;
			default:
				printf("\n wrong choice");	
		}
    }
    getch();
}
void cqinsert()
{
	int item;
	if(front==(rear+1)%(SIZE+1))
		printf("queue is full");
	else
	{
		printf("enter the no to insert");
		scanf("%d",&item);
		
		cq[rear]=item;
			rear=(rear+1)%SIZE;
	
	}
}
void cqdelet()
{   
    int item;
	if(front==rear)
		printf("queue is empty");
	else
	{   
		
			item=cq[front];
			printf("\n delet data=%d",item);
			front=(front+1)%(SIZE);
	}
}
void cqtraverse()
{
	int i;
	if(front==rear)
		printf("\n queue is empty");
	else
	{
		for(i=front;i!=rear;i=(i+1)%(SIZE+1))
			printf("%d\t",cq[i]);
	}
}
