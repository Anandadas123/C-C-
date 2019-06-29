#include<stdio.h>
#include<conio.h>
#include<string.h>
int  main()
{
	char str1[100],str2[100];
	int i,j,p,q,a[100],b[100],c[100],r,s=0;
	printf("\nenter the 1st string::(upto finite decimal digit)");
	gets(str1);
	p=strlen(str1);
	printf("\n                        +                \n");
	printf("\nenter the 2nd string::(upto finite decimal digit)");
	gets(str2);
	q=strlen(str2);
	q--;
	p--;
	for(i=0;i<=p;i++)
	{
		a[i]=str1[i]-48;
	}
	for(i=0;i<=q;i++)
	{
		b[i]=str2[i]-48;
	}
	if(p>q)
	{
		r=p;
		j=p;
		for(i=p;i>=0;i--)
		{
			if(q>=0)
			{
			b[i]=b[q];
			q--;
		    }
		    else
		    	b[i]=0;
		}
	}
	if(p<q)
	{
		r=q;
		j=q;
		for(i=q;i>=0;i--)
		{
			if(p>=0)
			{
			a[i]=a[p];
			p--;
		    }
		    else
		    a[i]=0;
		}
	}
	if(p==q)
	{
		r=p;
		j=p;
    }	
    printf("_____________________________________");
	printf("\n the adition=>        ");
	while(r>0)
	{
		c[r]=(s+(a[r]+b[r]))%10;
		s=(a[r]+b[r])/10;
		r--;
		
	}
	c[r]=s+a[r]+b[r];
	for(i=0;i<=j;i++)
	{
		printf("%d",c[i]);
	}
}
