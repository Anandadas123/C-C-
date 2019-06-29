#include<stdio.h>
int main()
{
	int x,y,z;
	printf("\n enter three no::");
	scanf("%d%d%d",&x,&y,&z);
	x=x+y+z;
	z=x-(y+z);
	y=x-(z+y);
	x=x-(y+z);
	printf("\nx=%d\ny=%d\nz=%d",x,y,z);
}
