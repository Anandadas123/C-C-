#include<stdio.h>
#include<math.h>
int main()
{
	float a;
	printf("\n enter the floating no::");
	scanf("%f",&a);
	int d=a,p,s=0,q,num=0;
	printf("%d\n",d);
	while(d>0)
	{
		p=d%10;
		s=s*10+p;
		d=d/10;
	}
	while(s>0)
	{
		q=s%10;
		num=num*10+q;
		s=s/10;
	}
	float exo=a-num;
	//printf("%g\n",a);
	printf("%f",exo);
}
