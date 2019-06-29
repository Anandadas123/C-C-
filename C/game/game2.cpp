#include<stdio.h>
#include<conio.h>
#include<time.h>
int call();
int a[9]={};
void test();
clock_t start,end;
int main()
{
	
	 int i,j,k,n,flag,count=0,m,p;
	 
	printf("enter the lable::");
     scanf("%d",&p);
	 for(i=876543210;i>=123456780;i--)
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
	 	a[++m]=n%10;
	 	n=n/10;
	 	a[++m]=n;
	 	flag=0;
	 	for(j=0;j<8;j++)
	 	{
			 for(k=j+1;k<9;k++)
	 		{
	 			if(a[j]==a[k]||a[j]==9||a[k]==9)
	 			{
	 				flag=1;
	 				break;
	 			}
	 		}
	 		
	 	 }
	 	if(flag==0)
	 	{
	 		count++;
	 		if(count==p)
	 			break;
	 	}
	}
	test();
}

void test()
{	
	printf("\n************MAGIC PUZZLE*********\n");
	printf("\t****time is start****");
	start=time(NULL);
	while(1)
	{
	
		printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,203,205,205,205,205,205,203,205,205,205,205,205,187);
		printf("%c     %c     %c     %c\n%c  %d  %c  %d  %c  %d  %c\n%c     %c     %c     %c\n",186,186,186,186,186,a[0],186,a[1],186,a[2],186,186,186,186,186);
    
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,206,205,205,205,205,205,206,205,205,205,205,205,185);
   		printf("%c     %c     %c     %c\n%c  %d  %c  %d  %c  %d  %c\n%c     %c     %c     %c\n",186,186,186,186,186,a[3],186,a[4],186,a[5],186,186,186,186,186);
   	 
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,206,205,205,205,205,205,206,205,205,205,205,205,185);
		printf("%c     %c     %c     %c\n%c  %d  %c  %d  %c  %d  %c\n%c     %c     %c     %c\n",186,186,186,186,186,a[6],186,a[7],186,a[8],186,186,186,186,186);
    
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,202,205,205,205,205,205,202,205,205,205,205,205,188);
		if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5&&a[5]==6&&a[6]==7&&a[7]==8&&a[8]==0)
			break;
		else
			call();
	}
	printf("\n**********puzzle is complite*********\n");
	end=time(NULL);
	int t=difftime(end,start);
	printf("\n total time= %d minute %d sec",t/60,t%60);
	printf("\n*********GAME IS SOLVED**************\n");
}
int call(){
	int i,j;
	printf("\n enter the move element::");
	char ch=getch();
if(ch=='M'||ch=='K'||ch=='P'||ch=='H')
{
	
	for(i=0;i<9;i++)
	{
			if(a[i]==0&&ch=='K')
			{
			
			  	if(((i>=0&&i<2)||(i>=3&&i<5)||(i>=6&&i<8)))
			  	{
					j=a[i];
					a[i]=a[i+1];
					a[i+1]=j;
					break;
			  	}
			 	else
				{
					printf("\n wrong enter,plz try again::\n");
					break;
				}
		    }
		    else if(a[i]==0&&ch=='H')
		    {
				if(((i>=0&&i<=5)))
				{
					j=a[i];
					a[i]=a[i+3];
					a[i+3]=j;
					break;
				}
				else
				{
					printf("\n wrong enter,plz try again::\n");
					break;
				}
		    }
		    else if(a[i]==0&&ch=='P')
		  
			{
				if((i>=3&&i<=8))
				{
					j=a[i];
					a[i]=a[i-3];
					a[i-3]=j;
					break;
				}
				else
				{
					printf("\n wrong enter,plz try again::\n");
					break;
				}
		    }
		    else if(a[i]==0&&ch=='M')
		    {
				if(((i<=2&&i>0)||(i<=5&&i>3)||(i<=8&&i>6)))
				{
					j=a[i];
					a[i]=a[i-1];
					a[i-1]=j;
					break;
				}
				else
				{
					printf("\n wrong enter,plz try again::\n");
					break;
				}
			}
	}
}
else
	{
		printf("\n wrong enter,plz try again::\n");	
	}	
}
