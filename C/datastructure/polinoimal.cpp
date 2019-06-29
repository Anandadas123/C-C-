#include<stdio.h>
#include<conio.h>

struct typedef pol_noimal
{
	float coef;
	int expo;
	struct node *link;
};
pol_noimal *start1=NULL,start2=NULL,*temp;
void creat();
void disply(pol_noimal *);
void insert_s(pol_noimal *,float,int);


int main()
{
	printf("Enter polynomial 1 :\n");
	start1=create(start1);

	printf("Enter polynomial 2 :\n");
	start2=create(start2);

	printf("Polynomial 1 is :  ");
	display(start1);
	printf("Polynomial 2 is :  ");
	display(start2);
		
	poly_add(start1, start2);
}
void creat()
{
	int i,n,ex;
	float co;
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter coeficient for term %d : ",i);
		scanf("%f",&co);
		printf("Enter exponent for term %d : ",i);
		scanf("%d",&ex);
		start=insert_s(start,co,ex);
}
void insert_s(pol_noimal *..
.)
