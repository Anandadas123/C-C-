#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int x=100;
	printf("%d\n",10+x++);
	printf("%d\n",10+ ++x);
	x=1;
	printf("%d%d%d%d\n",x++,++x,x++,x);
	x=1;
	printf("%d%d%d%d",++x,++x,x++,x);
}
