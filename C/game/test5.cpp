#include<stdio.h>
int main()
{
	static int i;
	if(i<5)
	{
		i++;
		main();
		printf("%d ",i);
		
	}
//	return 0;
}
