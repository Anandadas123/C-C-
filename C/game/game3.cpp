#include<stdio.h>
int main()
{
	 char a[100],i,d;
	a[5]='B';
	a[7]='B';
	a[20]='B';
	a[4]='B';
	a[10]='B';
	a[55]='B';
	a[22]='B';
	a[67]='B';
	a[98]='B';
	a[99]='B';
	a[31]='B';
	/*for(i=0;i<100;i++)
	{
			printf("|");
			if(a[i]=='B')
				printf("B");
			else 
				printf(" ");
		if((i+1)%10==0)	
		{
			printf("");
			printf("|");
			printf("\n");
		}
	}
	printf("\n");*/
	for(i=0;i<100;i++)
	{	d=0;
	if(a[i]!='B')
	{
		if(i==0)
		{
			if(a[i+1]=='B')
				d++;
			if(a[i+10]=='B')
				d++;
			if(a[(i+10)+1]=='B')
				d++;
			a[i]=(d+48);
			continue;	
		}
		else if(i==9)
		{
			if(a[i-1]=='B')
				d++;
			if(a[i+10]=='B')
				d++;
			if(a[(i+10)-1]=='B')
				d++;
			a[i]=(d+48);
			continue;	
		}
		else if(i==90)
		{
			if(a[i+1]=='B')
				d++;
			if(a[i-10]=='B')
				d++;
			if(a[(i-10)+1]=='B')
				d++;
			a[i]=(d+48);
			continue;	
		}
		else if(i==99)
		{
			if(a[i-1]=='B')
				d++;
			if(a[i-10]=='B')
				d++;
			if(a[(i-10)-1]=='B')
				d++;
			a[i]=(d+48);
			continue;	
		}
		else if((i>0&&i<9))
		{
			if(a[i-1]=='B')
				d++;
			if(a[i+1]=='B')
				d++;
			if(a[i+10]=='B')
				d++;
			if(a[(i+10)-1]=='B')
				d++;
			if(a[(i+10)+1]=='B')
				d++;
			a[i]=(d+48);
				continue;
		}
		else if((i>90&&i<100))
		{
			if(a[i-1]=='B')
				d++;
			if(a[i+1]=='B')
				d++;
			if(a[i+10]=='B')
				d++;
			if(a[(i-10)-1]=='B')
				d++;
			if(a[(i-10)+1]=='B')
				d++;
			a[i]=(d+48);
				continue;
		}
		else if(i==10||i==20||i==30||i==40||i==50||i==60||i==70||i==80)
		{
			if(a[i-10]=='B')
				d++;
			if(a[i+1]=='B')
				d++;
			if(a[i+10]=='B')
				d++;
			if(a[(i-10)+1]=='B')
				d++;
			if(a[(i+10)+1]=='B')
				d++;
			a[i]=(d+48);
			continue;
		}
		else if(i==19||i==29||i==39||i==49||i==59||i==69||i==79||i==89)
		{
			if(a[i-1]=='B')
				d++;
			if(a[i-10]=='B')
				d++;
			if(a[i+10]=='B')
				d++;
			if(a[(i+10)-1]=='B')
				d++;
			if(a[(i-10)-1]=='B')
				d++;
			a[i]=(d+48);
			continue;
		}
		else
		{
			if(a[i-1]=='B')
				d++;
			if(a[i+1]=='B')
				d++;
			if(a[i+10]=='B')
				d++;
			if(a[i-10]=='B')
				d++;
			if(a[(i-10)-1]=='B')
				d++;
			if(a[(i-10)+1]=='B')
				d++;
			if(a[(i+10)-1]=='B')
				d++;
			if(a[(i+10)+1]=='B')
				d++;
			a[i]=(d+48);
		}
	}
	else
		continue;
			
		
	}
	printf("---------------------\n");
	for(i=0;i<100;i++)
	{
		printf("|");
		if(a[i]=='0')
			printf(" ");
		else
			printf("%c",a[i]);
		if((i+1)%10==0)
		{
			printf("|");
			printf("\n");
			printf("---------------------\n");
		}
	}
}