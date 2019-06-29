#include<stdio.h>
#include<conio.h>
int call()
{
	int n;
	char ch;
	printf("\nenter your age:");
	scanf("%d",&n);
	if(n>=18)
		printf("man is votter");
	else
		printf("man is not votter");
	printf("\nare you want to contiue::(y/Y)");
	ch=getch();
	if(ch=='y'||ch=='Y')
	call();
}
int main()
{
	call();
}
