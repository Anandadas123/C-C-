#include <stdio.h>

int main()
{
    int i,j,a[100][100],min,d=0,t,n;
    scanf("%d",&t);
    scanf("%d",&n);
    while(t>0)
    {
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			scanf("%d",&a[i][j]);
    		}
    	}
    	for(i=0;i<n;i++)
    	{
    		min=a[i][0];
    		for(j=1;j<n;j++)
    		{
    			
    			if(a[i][j]<min)
    			min=a[i][j];
    		}
    		d+=min;
    	}
    
    	t--;
    }
    printf("%d",d);
    
}
