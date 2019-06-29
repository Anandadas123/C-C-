#include<stdio.h>
#include<conio.h>
int main()
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31},d,m,y,day,count=0,j=0,p,k,i,l;
	char ch;
	printf("\n enter  the date(d/m/y):::");
	scanf("%d/%d/%d",&d,&m,&y);
	if((y%4==0&&y%100!=0)||y%400==0)
    	a[1]=29;
	for(k=0;k<m-1;k++)
	{
		j=j+a[k];
	}
	if((a[m-1]<d && a[1]!=29)|| a[m-1]<d)
	{
	 printf("\n You enter wrong  date(please enter valid date)...");
	 main();
	}
	else
		printf("The  date is valid");
	
}
