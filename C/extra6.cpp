#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	unsigned x=1;
	printf("%d",sizeof(unsigned));
	signed char y=-1;
	printf("%c",y);
	printf("%d",sizeof(signed char));
	if(x>y)
	printf("x>y");
	else
	printf("x<y");
}
