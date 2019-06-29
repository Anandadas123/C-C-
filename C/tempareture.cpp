#include<stdio.h>
#include<conio.h>
#define F_LOW 0
#define F_MAX 250
#define STEP 25
int main()
{
	float farenhite,celcise;
	farenhite=F_LOW;
	printf("\n farenhite celcise");
	while(farenhite<=F_MAX)
	{
		celcise=(farenhite-32.00)/1.8;
		printf("\n%5.1f%7.2f\n",farenhite,celcise);
		farenhite+=STEP;
	}
}
