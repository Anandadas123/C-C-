#include<stdio.h>
#include<conio.h>
int main()
{
	int HH,MM;
	float cl_angle;
	printf("\n enter the time(hh::mm)");
	scanf("%d::%d",&HH,&MM);
	cl_angle=((5.5*MM)-(30*HH));
	if(cl_angle<0)
	cl_angle=-cl_angle;
	printf("\n the angle between two hands is=%fdegree",cl_angle);
}
