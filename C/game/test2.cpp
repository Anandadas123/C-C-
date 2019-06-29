#include<stdio.h>
#include<conio.h>
int main()
{
	 //int i,n,d1,d2,d3,d4,a[4],p=0;
	 int i,j,k,n,a[8]={},flag,count=0,m,p;
	// printf("enter the count");
	// scanf("%d ",&p);
	 
	/* for(i=1234;i<=4321;i++)
	 {
	 	n=i;
	 	d1=n%10;
	 	n=n/10;
	 	d2=n%10;
	 	n=n/10;
	 	d3=n%10;
	 	n=n/10;
	 	d4=n;
	 	if((d1!=d2&&d1!=d3&&d1!=d4)&&(d2!=d3&&d2!=d4)&&(d3!=d4)&&(d1>=1&&d1<=4)&&(d2>=1&&d2<=4)&&(d3>=1&&d3<=4)&&(d4>=1&&d4<=4))
	 	printf("%d\n",i);
	 }*/
	 for(i=87654321;i>=12345678;i--)
	 {
	 	m=0;
	 	n=i;
	 	a[m]=n%10;
	 	n=n/10;
	 	a[++m]=n%10;
	 	n=n/10;
	 	a[++m]=n%10;
	 	n=n/10;
	 	a[++m]=n%10;
	 	n=n/10;
	 	a[++m]=n%10;
	 	n=n/10;
	 	a[++m]=n%10;
		 n=n/10;
	 	a[++m]=n%10;
	 	n=n/10;
	 	a[++m]=n;
	 	flag=0;
	 	for(j=0;j<7;j++)
	 	{
			 for(k=j+1;k<8;k++)
	 		{
	 			if(a[j]==a[k]||a[j]==9||a[k]==9||a[j]==0||a[k]==0)
	 			{
	 				flag=1;
	 				break;
	 			}
	 		}
	 		if(flag==1)
	 		break;
	 	 }
	 	if(flag==0)
	 	{
	 		count++;
	 		//if(count==p)
	 		{
	 		printf("%d\n",i);
	 		//break;
	 		}
	 		
	 	}
	}
	printf("total combination=%d",count);
	
}
