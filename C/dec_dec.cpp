#include<stdio.h>
#include<conio.h>
#include<math.h>
void call()
{
       long int n,s=0,m=0,d;
       char ch;
	printf("\n enter the decimal no::");
	scanf("%lu",&n);
	while(n!=0)
	{
	      d=n%2;
	      s=s+d*pow(10,m);
	      n=n/2;
	      m++;
	}
	printf("binary no is=%lu",s);
	printf("\nare you want to continue(y/Y)");
	ch=getche();
	if(ch=='y'||ch=='Y')
	 call();
}
int main()
{
	call();
	getch();
}
