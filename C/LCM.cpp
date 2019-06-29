#include<stdio.h>
#include<conio.h>
#include<math.h>
int  main()
{
	int a[20],i,n,count=0,m=1,p=1,k,s;
	printf("\n enter the two no for LCM::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	k=a[0];
	for(i=1;i<n;i++)
	{
		if(k<a[i])
			k=a[i];
	}
	for(i=0;i<n-1;i++)
	{
		m=1;
		while(m<=k)
		{
			if(a[i]%m==0&&a[i+1]%m==0)
			{
				p=m;
			    
			}
			m++;
		}
		a[i]/=p;
		a[i+1]/=p;
		s=p*a[i]*a[i+1];
		a[i+1]=s;
   }
	printf("\n the LCM=%d",s);
}
	
	
	
	
