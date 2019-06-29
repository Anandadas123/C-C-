#include<stdio.h>
static int i=1;
int call()
{
	//static int i=1;
	printf("kala");
	main();
	if(i<10)
	{
		i++;
		//main();
		printf("%d ",i);
	}	
}
int main()
{
	

//	printf("%d ",i);
		call();	
}
