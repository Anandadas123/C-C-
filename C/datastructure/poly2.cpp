#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define SIZE 50
void postfix_notation(int);
int postfix_evaluation();
int top=1,up=-1;
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
	length=strlen(postfix);
	printf("length=%d",length);
	int value=postfix_evaluation();
	printf("\n result=%d",value);
}
void postfix_notation(int p)
{
	int q=0,r=0,i;
	char ch;
	for(i=0;i<p;i++)
	{
		if(infix[i]<='9'&&infix[i]>='0')
			postfix[r++]=infix[i];
		//if(infix[i]=='+'||infix[i]=='-'||infix[i]=='%'||infix[i]=='*'||infix[i]=='^')
		//	postfix[r++]=',';
		else
		{
		if(infix[i]!='('||infix[i]!=')')
			postfix[r++]=',';
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
	int temp,a,b,i,result,q=0,t=0;
	for(t=0;t<strlen(postfix);t++)
	{
		if(postfix[t]!=',')
		{
			q=q*10+(postfix[t]-48);
		}
		if(postfix[t]!='0'||postfix[t]!='8'||postfix[t]!='9'||postfix[t]!='1'||postfix[t]=='2'||postfix[t]=='3'||postfix[4]=='/'||postfix[5]=='%'||postfix[6]=='*'||postfix[7]=='^')
		{
			push2(q);
			q=0;
		}
		
		if(postfix[t]=='+'||postfix[t]=='-'||postfix[t]=='/'||postfix[t]=='%'||postfix[t]=='*'||postfix[t]=='^')
		{
			b=pop2();
			a=pop2();
			switch(postfix[t])
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
void push2(int s)
{
	if(up<SIZE)
	{
		up++;
		stack2[up]=s;
		

	}
	else
		printf("\nthe stack is full");
}
int pop2()
{
	if(up>=0)
	{
		return (stack2[up--]);
	}
}
