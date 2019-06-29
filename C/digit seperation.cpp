#include<stdio.h>
void call(int);
int main()
{
	int n=2345,n1,n2,n3,n4;
	n1=n%10;
	n=n/10;
	
	n2=n%10;
	n=n/10;
	
	n3=n%10;
	n4=n/10;
	call(n4);
	if(n4!=0)
	printf("Thousand ");
	call(n3);
	if(n3!=0)
	printf("Handred ");
	if(n2==1)
	{

		switch(n1)
		{
			case 0:
				printf("Ten");
				break;
			case 1:
				printf("Eleven ");
				break;
			case 2:
				printf("Twelve ");
				break;
			case 3:
				printf("Therteen ");
				break;
			case 4:
				printf("Fourteen ");
				break;
			case 5:
				printf("Fifteen ");
				break;
			case 6:
				printf("Sixteen ");
				break;
			case 7:
				printf("Seventeen ");
				break;
			case 8:
				printf("Eightteen ");
				break;
			case 9:
				printf("Nineteen ");
		}
	}
	else if(n2>1)
	{
	switch(n2)
		{
			case 2:
				printf("Twenty ");
				break;
			case 3:
				printf("Threty ");
				break;
			case 4:
				printf("Fourty ");
				break;
			case 5:
				printf("Fifty ");
				break;
			case 6:
				printf("Sixty ");
				break;
			case 7:
				printf("Seventy ");
				break;
			case 8:
				printf("Eightty ");
				break;
			case 9:
				printf("Ninety ");		
	    }
		
	}
	if(n1>0)
	call(n1);
}
void call(int n)
{
	switch(n)
	{
		case 1:
			printf("One ");
			break;
		case 2:
			printf("Two ");
			break;
		case 3:
			printf("Three ");
			break;
		case 4:
			printf("Four ");
			break;
		case 5:
			printf("Five ");
			break;
		case 6:
			printf("Six ");
			break;
		case 7:
			printf("Seven ");
			break;
		case 8:
			printf("Eight ");
			break;
		case 9:
			printf("Nine ");		
	}
}
