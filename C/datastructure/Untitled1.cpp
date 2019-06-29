#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define SIZE 50
void postfix_notation(int);
int postfix_evaluation();
int i,top=1,up=0,r=0;
char stack1[SIZE]={'#','('};
int stack2[SIZE];
void push1(char );
int pop1();
void push2(int);
int pop2();
int priority(char);
char infix[SIZE];
char postfix[SIZE];
int main()
{
	int length,i;
	printf("\n enter the infix notation::");
	gets(infix);
	length=strlen(infix);
	infix[length++]=')';
	infix[length]='\0';
	printf("%c",infix[0]);
	postfix_notation(length);
	printf("\n  the post_fix notation is::\n");
//	for(i=0;i<r;i++)
		printf("%s",postfix);
	//length=strlen(postfix);
	//printf("length=%d",length);
	int value=postfix_evaluation();
	printf("\n result=%d",value);
}
void postfix_notation(int p)
{
	int q=0,t=0;
	char ch;
	for(t=0;t<p;t++)
	{
		if(infix[t]<='9'&&infix[t]>='0')
			postfix[r++]=infix[t];
		else
		{
		if(infix[t]!='('||infix[t]!=')')
			postfix[r++]=44;
			
			
		switch(infix[t])
		{
			case '(':
				push1(infix[t]);
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
			default:
				{
					//	if(infix[t]=='+')
						push1((infix[t]));
					//	postfix[r++]=44;
					/*	if(infix[t]=='*')
						push1((infix[t])-42);
						if(infix[t]=='/')
						push1((infix[t])-47);
						if(infix[t]=='-')
						push1((infix[t])-45);
						if(infix[t]=='%')
						push1((infix[t])-37);
						if(infix[t]=='+')
						push1((infix[t])-94);*/
				}
				//
		}
		
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
	int temp,a,b,i,result,q=0;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]!=',')
		{
			q=q*10+(postfix[i]-48);
		}
		
		if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='/'||postfix[i]=='%'||postfix[i]=='*'||postfix[i]=='^')
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
		if(postfix[i]==',')
		{
		push2(q);
		q=0;
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
