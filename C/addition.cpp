#include<stdio.h>
#include<conio.h>
 int func(int x,int y,int *ps,int *pd,int *pp);
  main()
{
	int x,y,sum,diff,mul;
	printf("enter the two no::");
	scanf("%d%d",&x,&y);
	func( x,y,&sum,&diff,&mul);
	printf("sum=%d\tdiff=%d\t mul=%d",sum,diff,mul);
}
int func(int x,int y,int *ps,int *pd,int *pp)
{
	*ps=x+y;
	*pd=x-y;
	*pp=x*y;
}
