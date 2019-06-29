#include<stdio.h>
#include<conio.h>
int main()
{
	int d1,m1,y1,d2,m2,y2,d,m,y,w;
	printf("\n enter the recent date(d/m/y)::\n");
	scanf("%d/%d/%d",&d1,&m1,&y1);
	printf("\n enter your date of birth(d/m/y)::\n");
	scanf("%d/%d/%d",&d2,&m2,&y2);
	if(d1<d2)
	{
		d1=d1+30;
		m1--;
	}
	if(m1<m2)
	{
		m1=m1+12;
		y1--;
	}
	d=d1-d2;
	w=d/7;
	d=d%7;
	m=m1-m2;
	y=y1-y2;
	printf("\n your age is=>");
	if(y>1)
		printf("%d years ",y);
	else if(y==0)
		printf(" ");
	else
		printf("%d year ",y);
	if(m>1)
		printf(" %d months ",m);
	else if(m==0)
		printf(" ");
	else
		printf("%d month ",m);
	if(w>1)
		printf(" %d weeks ",w);
	else if(w==0)
		printf(" ");
	else
		printf("%d week ",w);
	if(d>1)
		printf(" %d days ",d);
	else if(d==0)
		printf(" ");
	else
		printf("%d day ",d);	
}
