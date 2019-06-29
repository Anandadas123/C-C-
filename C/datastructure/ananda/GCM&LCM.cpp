#include<stdio.h>
#include<conio.h>
int main()
{
	int x,y,z,a,b,c,i,hcf=1;
	printf("enter the three no:");
	scanf("%d%d%d",&x,&y,&z);
	a=x;
	b=y;
	c=z;
	while((a!=b)||(b!=c)||(c!=a))
	{
		if(a<b&&a<c)
			a=a+x;
   	else if(b<c)
      	b=b+y;
   	 else
       	c=c+z;
	}
	printf("\nthe LCM of three no is :%d",a);
	for(i=2;i<=x&&i<=y&&i<=z;i++)
	{
		while(x%i==0&&y%i==0&&z%i==0)
		{
    		hcf=hcf*i;
    		x=x/i;
    		y=y/i;
    		z=z/i;
		}
	}
	printf("\nthe hcf of the three no is: %d",hcf);
   getch();
}
