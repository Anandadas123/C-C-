#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int i,d=0,y=0,p,m,d1,m1,m2,d2,y1,y2;
	char str[20];
	strcpy(str,__DATE__);
	printf("%s",str);
		switch(str[2])
		{
		    
		    case 'n':
				m=1;
				break;
		    case 'b':
				m=2;
				break;
		    case 'r':
				m=3;
				break;
		    case 'y':
				m=5;
				break;
		    case 'l':
				m=7;
				break;
		    case 'g':
				m=8;
				break;
		    case 'p':
				m=9;
				break;
		    case 't':
				m=10;
				break;
		    case 'v':
				m=11;
				break;
		    case 'c':
				 m=12;
		}
		if(str[1]=='p'&&str[2]=='r')
			m=4;
		if(str[1]=='u'&&str[2]=='n')
			m=6;
		if(str[4]==' ')
			d=0;
		else
			d=(str[4]-48);
	for(i=5;i<strlen(str);i++)
	{
		if(i==5)
			  p=d*10+(str[5]-48);
		if(i>6&&str[i]!='\0')
			 y=y*10+(str[i]-48);
	}
	d=p;
//	printf("\n day=%d\n month=%d\nyear=%d",d,m,y);
	printf("\n enter your date of birth(d/m/y)::\n");
	scanf("%d/%d/%d",&d2,&m2,&y2);
	if(d<d2)
	{
		d=d+30;
		m--;
	}
	if(m<m2)
	{
		m=m+12;
		y--;
	}
	d1=d-d2;
	m1=m-m2;
	y1=y-y2;
	printf("\n your age is=>%d years %d months %d days",y1,m1,d1);
//getch();

}
