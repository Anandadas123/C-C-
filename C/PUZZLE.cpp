#include<stdio.h>
int main()
{
	int x,y,z;
	printf("\n enter the three no x,y,z::");
	scanf("%d%d%d",&x,&y,&z);
	x=x+y+z;
	z=x-(y+z);
	y=x-(y+z);
	x=x-(y+z);
	printf("\nx=%d \n y=%d \n z=%d ",x,y,z);
	
}
