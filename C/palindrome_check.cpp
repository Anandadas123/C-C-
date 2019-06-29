#include<stdio.h>
#include<string.h>
int palindrome(char p[],int i,int j,int n)
{
	if(i>j && n<i)
		return 1;
	else
	{

		if(p[i]==p[j])
			palindrome(p,++i,--j,n);
		else 
			return 0;
	}
	
}
int main()
{
	char str[100];
	printf("Enter the number::");
	gets(str);
	int n=palindrome(str,0,strlen(str)-1,strlen(str)/2);
	if(n==0)
		printf("\nString is not palindrome");
	else
		printf("\nString is  palindrome");
}

