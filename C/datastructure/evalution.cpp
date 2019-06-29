#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define SIZE 50
void postfix_notation(int);
int postfix_evaluation();
int i,top=1,up=0;
char stack1[SIZE]={'#','('};
int stack2[SIZE];
void push1(char );
int pop1();
void push2(int);
int pop2();
int priority(char);
char infix[SIZE],postfix[SIZE];
int main()
{
	int length;
	printf("\n enter the infix notation::");
	gets(infix);
	length=strlen(infix);
	infix[length++]=')';
	infix[length]='\0';
	postfix_notation(length);
	printf("\n  the post_fix notation is::\n");
	printf("%s",postfix);
	//length=strlen(postfix);
	//printf("length=%d",length);
	int value=postfix_evaluation();
	printf("\n result=%d",value);
}
void postfix_notation(int p)
{
	int r=0;
	char ch;
	for(i=0;i<p;i++)
	{
		switch(infix[i])
		{
			case '(':
				push1(infix[i]);
				break;
			case ')':
				while((ch=pop1())!='(')
				{
					postfix[r++]=ch;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
			while(priority(stack1[top])>=priority(infix[i]))
				postfix[r++]=pop1();
			push1(infix[i]);
			break;
			default:
				postfix[r++]=infix[i];
		}
	}
	postfix[r++]='\0';
}
void push1(char q)
{
	if(top<SIZE)
	{
		top++;
		stack1[top]=q;

	}
	else
		printf("\nthe stack is full");
}
int pop1()
{
	if(stack1[top]>0)
	{
		return (stack1[top--]);
	}
}
int priority(char s)
{
	switch(s)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
	}
}
int postfix_evaluation()
{
	int temp,a,b,i,result;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]<='9'&&postfix[i]>='0')
			push2(postfix[i]-48);
		else
		{
			b=pop2();
			a=pop2();
			switch(postfix[i])
			{
				case '+':
					temp=a+b;
					break;
				case '-':
					temp=a-b;
					break;
				case '*':
					temp=a*b;
					break;
				case '/':
					temp=a/b;
					break;
				case '%':
					temp=a-b;
					break;
				case '^':
					temp=pow(a,b);
			}
			push2(temp);
		}
		
	}
	result=pop2();
	return result;
}
void push2(int q)
{
	if(up<SIZE)
	{
		up++;
		stack2[up]=q;

	}
	else
		printf("\nthe stack is full");
}
int pop2()
{
	if(stack2[up]>=0)
	{
		return (stack2[up--]);
	}
}
