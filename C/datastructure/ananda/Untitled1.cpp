#include<stdio.h>
#include<conio.h>
int main()
{
	int a[4][4],i,j,r,flag=0,count=0;
   	printf("enter the row or column:");
   	scanf("%d",&r);
   	printf("ENTER THE ARRAY ELEMENT:\n");
   	for(i=0;i<r;i++)
   	{
   		for(j=0;j<r;j++)
      	{
      		scanf("%d",&a[i][j]);
      	}
   }
   printf("THE ARRAY ELEMENT ARE:\n");
   for(i=0;i<r;i++)
   {
   		for(j=0;j<r;j++)
    	{
      		printf("%d\t",a[i][j]);
      	}
      	printf("\n\n");
   }
   for(i=0;i<r;i++)
   {
		for(j=0;j<r;j++)
      	{
         	if(a[i][j]!=a[j][i])
         	{
            	flag=1;
         	}
		 	if(a[i][j]==-a[j][i])
         	{
            	count++;
         	}    
         }
	}
	if(count==r*r)
	{
		printf("the matrix is skew_symetric");
	}
 	else if(flag==1)
		 printf("the matrix is   not symetric & skew_symetric");
	else
		printf("the matrix is symetric");
	getch();
}
