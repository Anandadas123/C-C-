#include<stdio.h>
//#include<conio.h>
int main()
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31},d,m,y,day,count=0,j=0,p,k,i,l;
	char ch;
	printf("\n enter the date(d/m/y):::");
	scanf("%d/%d/%d",&d,&m,&y);
	if((y%4==0&&y%100!=0)||y%400==0)
    	a[1]=29;
	for(k=0;k<m-1;k++)
	{
		j=j+a[k];
	}
	if((a[m-1]<d && a[1]!=29)|| a[m-1]<d)
	{
	 	printf("\n Enter the valid date:");
	 	main();
	 }
	for(i=1;i<=(y-1);i++)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		count++;
	}
	//printf("%d",count);
	day=count+y+j;
	l=(day+d)%7;
	day=(day)%7;
	switch(l)
	{
		case 0:printf("\n the day is Satarday\n");
			break;
		case 1:printf("\n the day is Sunday\n");
			break;
		case 2:printf("\n the day is Monday\n");
			break;
		case 3:printf("\n the day is Tuesday\n");
			break;
		case 4:printf("\n the day is Wednesday\n");
			break;
		case 5:printf("\n the day is Thursday\n");
			break;
		case 6:printf("\n the day is Friday\n");
	}
	printf("\n__________________________________________");
	printf("\n  Sun  Mon   Tue  Wed  Thus  Fri  Sat");
    printf("\n__________________________________________\n");
	for(p=0;p<day;p++)
	{
		printf("     ");
    }
	for(i=1;i<=a[m-1];i++)
	{
		printf("   %2d",i);
		if((p+i)%7==0)
			printf("\n\n");
	}
	 printf("\n__________________________________________\n");
   // fflush(stdin);
   // printf("\n if you want to continue press(y/Y)");
   // scanf("%c",&ch);
   // ch=getche();
   // if(ch=='y'||ch=='Y')
   // main();
   // else
   // {
   // 	printf("\n wrong choice");
	//}
	
}
