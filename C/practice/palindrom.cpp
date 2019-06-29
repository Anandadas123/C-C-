#include<stdio.h>
#include<string.h>
int fact(int);
int main()
{
	char s[100],s1[100],s2[100];
	int i=1,p,d=0;
	gets(s);
	p=strlen(s);
	int r=p;
	while(p>0)
	{
		d=d+fact(r)/(fact(i)*fact(r-i));
		p--;
		i++;
	}
	d=d-p;
	for(i=0;i<d;i++)
	{
		s1[i]=s[i];
		s2[i]=s[i+1];
	}
	printf("%d",d);
	
}
int fact(int n)
{
	int fact=1;
	for(int i=n;i>0;i--)
		fact=fact*i;
	return fact;
}
