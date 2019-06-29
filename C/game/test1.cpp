#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
int call();
int a[9]={1,2,3,7,4,5,8,0,6};
int main()
{
//	clock_t start,end;
//	start=time(NULL);

	while(1)
	{
	
		printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,203,205,205,205,205,205,203,205,205,205,205,205,187);
		printf("%c     %c     %c     %c\n%c  %d  %c  %d  %c  %d  %c\n%c     %c     %c     %c\n",186,186,186,186,186,a[0],186,a[1],186,a[2],186,186,186,186,186);
    
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,206,205,205,205,205,205,206,205,205,205,205,205,185);
   		printf("%c     %c     %c     %c\n%c  %d  %c  %d  %c  %d  %c\n%c     %c     %c     %c\n",186,186,186,186,186,a[3],186,a[4],186,a[5],186,186,186,186,186);
   	 
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,206,205,205,205,205,205,206,205,205,205,205,205,185);
		printf("%c     %c     %c     %c\n%c  %d  %c  %d  %c  %d  %c\n%c     %c     %c     %c\n",186,186,186,186,186,a[6],186,a[7],186,a[8],186,186,186,186,186);
    
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,202,205,205,205,205,205,202,205,205,205,205,205,188);
		if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5&&a[5]==6&&a[6]==7&&a[7]==8&&a[8]==0)
			break;
		else
			call();
	
	}
	printf("\n puzzle is complite::");
//	end=time(NULL);
//	printf("\n total time= %f sec",(difftime(end,start)));
}
int call(){
	int i,j;
	printf("\n enter the move element::");
	char ch=getche();
/*	if(ch!='M'||ch!='P'||ch!='H'||ch!='K')
	{
		printf("\n wrong enter,plz try again::\n");
		return 0;
	}*/
	
if(ch=='M'||ch=='P'||ch=='H'||ch=='K')
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
