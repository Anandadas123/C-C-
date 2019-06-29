#include<stdio.h>
#include<conio.h>
int  main()
{
	unsigned long	int a[20]={ },b[20]={ },j,i,n,q=1,m,p=1,s,k;
	printf("\n how many no you want to for LCM&&GCM::");
	scanf("%lu",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lu",&a[i]);
		b[i]=a[i];
	}
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
				p=m;
			if(b[i]%m==0&&b[i+1]%m==0)
				q=m;		
			m++;
		}
		a[i]/=p;
		a[i+1]/=p;
		s=p*a[i]*a[i+1];
		a[i+1]=s;
		b[i+1]=q;
   }
   printf("\n the GCM=%lu\n",q);
   printf("\n the LCM=%lu\n",s);
}
	
	
	
