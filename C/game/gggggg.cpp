#include<stdio.h>
int main()
{
	
	  int j,k,n,flag,m,p,i,count=0;
	  char a[9];
	 
//	printf("enter the lable::");
  //   scanf("%d",&p);
	 for(i=876543210;i>=12345678;i--)
	 {
	 	//printf("\n%d",i);
	 	m=0;
	 	n=i;
	 	a[m]=n%10+48;
	 	n=n/10;
	 	a[++m]=n%10+48;
	 	n=n/10;
	 	a[++m]=n%10+48;
	 	n=n/10;
	 	a[++m]=n%10+48;
	 	n=n/10;
	 	a[++m]=n%10+48;
	 	n=n/10;
	 	a[++m]=n%10+48;
		 n=n/10;
	 	a[++m]=n%10+48;
	 	n=n/10;
	 	a[++m]=n%10+48;
	 	n=n/10;
	 	a[++m]=n+48;
	 	flag=0;
	 	for(k=0;k<8;k++)
	 	{
			 for(j=k+1;j<9;j++)
	 		{
	 			if(a[k]==a[j]||a[j]=='9'||a[k]=='9')
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
	 		printf("%d   ",i);
	 	//	count++;
	 	//	if(p==count)
	 		{
	 		//	count=0;
	 		//test();
	 		//	break;
	 		}
	 	}
	 	//flag=0;
	}

//	test();
}
