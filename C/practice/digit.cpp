#include<stdio.h>
int call(int n)
{
	/*if(n!=0)
		call(n/10);
	else
		return;*/
	int d=n%10;
		if(n==0)
			return 0;
		else
			call(n/10);
	switch(d)
		{
			case 0:
				printf("zero ");
				break;
			case 1:
				printf("one ");
				break;
			case 2: 
				printf("two ");
				break;
			case 3:
				printf("three ");
				break;
			case 4:
				printf("four ");
				break;
			case 5:
				printf("five ");
				break;
			case 6:
				printf("six ");
				break;
			case 7:
				printf("seven ");
				break;
			case 8:
				printf("eight ");
				break;
			case 9:
				printf("nine ");
				
		}
}
int main()
{
	int i;
	printf("enter the no");
	scanf("%d",&i);
	call(i);
}
