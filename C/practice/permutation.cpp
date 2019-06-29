#include<stdio.h>
int main()
{
    long int a,b,i,j,k;
    scanf("%d%d",&a,&b);
    long int a1[a],a2[a],a3[a];
    for(i=0;i<a;i++)
    	scanf("%d",&a1[i]);		
    for(i=0;i<a;i++)
    	scanf("%d",&a2[i]);	
    for(i=0;i<b-1;i++)
    {
    	for(j=0;j<a;j++)
    	{
    		for(k=0;k<a;k++)
    		{
    			if(a1[k]==a2[j])
    			{
    				a3[k]=a1[j];
    				break;
    			}
    		}
    	}
    	for(j=0;j<a;j++)
    	{
    		a1[j]=a2[j];
    		a2[j]=a3[j];	
    	}
    }
    for(i=0;i<a;i++)
    printf("%d ",a2[i]);
}
