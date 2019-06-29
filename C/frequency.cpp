#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 10
#define COUNTER 11
int  main()
{
	int a[MAX];
	int i,low,high;
//	printf("how many no you want")
	int group[COUNTER]={};
	for(i=0;i<MAX;i++)
	{
		scanf("%d",&a[i]);
		++group[(a[i])/10];
	}
	printf("_________________________________________\n");
	printf("GROUP   RANG    FREQUENCY\n");
	printf("_________________________________________\n");
	for(i=0;i<COUNTER;i++)
	{
		low=i*10;
		if(i==10)
		high=100;
		else
		high=low+9;
		printf("%2d  %3d to %3d    %2d\n",i+1,low,high,group[i]);
	}
}
