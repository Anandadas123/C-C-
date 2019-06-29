#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	float m,x,x0,x1,xav,value;
	int a,b,c,d;
	//char str[20];
	printf("\n\t\tbisection method::");
	printf("\n enter the equation::");
	
	printf("enter the coefficient of the 3rd order::");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("\n\tenter the upper limit and lower limit::");
	scanf("%f%f",&m,&x1);
	 x0=(m+x1)/2;
	printf("\n x0\t\tx1\t\txav\t\tvalue");
	do{
		xav=(x0+x1)/2;
		value=a*(xav*xav*xav)+b*(xav*xav)+c*xav+d;
		printf("\n%f\t%f\t%f\t%f",x0,x1,xav,value);
		if(value>0.0)
			x0=xav;
		else
			x1=xav;
	}while(value!=0.000);
	
}
