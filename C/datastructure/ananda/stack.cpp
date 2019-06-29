#include<stdio.h>
#include<conio.h>
#define SIZE 3
void push();
void pop();
void traverse();
int stack[SIZE],top=0;
int main()
{
	int choice;
	while(1)
	{
		printf("\n 1.PUSH");
		printf("\n 2.POP");
		printf("\n 3.TRAVERS");
		printf("\n 4.EXIT");
		printf("\nENTER YOUR CHOICE");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
				break;
			case 2:
			    pop();
				break;
			case 3:
				traverse();
				break;
			default:
				printf("\n wrong choice");
			case 4:
				return 0;	
		}
    }
    getch();
}
void push()
{
	int item;
	if(top<SIZE)
	{
		printf("\nENTER THE ELEMENT TO INSERT");
		scanf("%d",&item);
		//top++;
		stack[top]=item;
		top++;
	
	}
	else
		printf("\nthe stack is full");
}
void pop()
{
	int item;
	if(top>0)
	{
		top--;
		item=stack[top];
		
		printf("\nthe no delet is %d",item);
		
	}
	else
		printf("\nstack is underflow");
}
void traverse()
{
	int i;
	if(top==0)
		printf("\nstack is empty");
	else
		{
			for(i=0;i<top;i++)
				printf(" %d\t",stack[i]);
		}
}
