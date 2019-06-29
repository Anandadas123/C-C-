#include<stdio.h>
int main()
{
	float a=23.459;
	//printf("%f\n",float(a));
	int d;
	while(d!=23459.0)
	{
		a=a*10;
		d=a;
	}
	printf("%d",d);
}
