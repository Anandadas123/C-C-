#include<stdio.h>
#include<conio.h>
#include<math.h>
int  main()
{
	long unsigned int n,count,n1,n2,n3;
	printf("\n enter the how many value ::");
	scanf("%lu",&n);
	n1=0;
	n2=1;
	count=2;
	printf("%lu  %lu",n1,n2);
	while(count<=n)
	{
		n3=n1+n2;
		count++;
		printf(" %lu",n3);
		n1=n2;
		n2=n3;
		
	}

}
