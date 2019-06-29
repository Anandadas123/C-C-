#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	float a,b,c,d,x1,x2,x;
	printf("enter the value of a,b,c::");
	scanf("%f%f%f",&a,&b,&c);
	d=b*b-4*a*c;
	if(d>0)
	{
		x1=(-b+sqrt(d)/(2*a));
		x2=(-b-sqrt(d)/(2*a));
		printf("\n roots are real and unequal");
		printf("\n %f and %f",x1,x2);
	}
	else if(d==0)
	{
		x=-b/(2*a);
		printf("\n roots are real equal");
		printf("\n %f",x);
	}
	else
		printf("\n no real roots,roots are complex");
}
