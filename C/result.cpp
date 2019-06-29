#include<stdio.h>
#include<conio.h>
#include<math.h>
#define ITEMS 10
#define STUDENT 3
int  main()
{
	char key[ITEMS+1],response[ITEMS+1];
	int i,count,student,n,correct[ITEMS+1];
	printf("\n input key to item\n");
	for(i=0;i<ITEMS;i++)
		scanf("%c",&key[i]);
	key[i]='\0';
	printf("\n");

for(student=1;student<=STUDENT;student++)
{
	count=0;
	printf("\n input response student-%d\n",student);
	for(i=0;i<ITEMS;i++)
		scanf("%c",&response[i]);
		scanf("%c",&response[i]);
	response[i]='\0';
	for(i=0;i<ITEMS;i++)
	correct[i]=0;
	for(i=0;i<ITEMS;i++)
	if(response[i]==key[i])
	{
		correct[i]=1;
		count++;
	}
	printf("\n");
	printf("\n student-%d\n",student);
	printf("%d scors out of %d items",count,ITEMS);
	printf("\n responce to the items to the rong\n");
	for(i=0;i<ITEMS;i++)
	if(correct[i]==0)
	{
		printf("%d ",i+1);
		n++;
	}
	if(n==0)
	printf("\nNILL");
}
}
