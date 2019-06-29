#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float s,A;
	printf("enter the three arun of the traingle::");
	scanf("%d%d%d",&a,&b,&c);
	s=float((a+b+c))/2;
	printf("%f",s);
	A=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("\n area of the traingle =%f",A);
	
}
