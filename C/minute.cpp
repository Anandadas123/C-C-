#include<stdio.h>
//#include<conio.h>
//#include<math.h>
int  main()
{
	int t;
	printf("enter the no of second");
	scanf("%d",&t);
	printf(" %d hours %d minute %d second  ",t/3600,(t%3600)/60,(t%3600)%60);
}
