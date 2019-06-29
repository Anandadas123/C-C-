#include<stdio.h>
void printarray(int a[],int);
void selection_short(int a[],int);
int main()
{
 int a[50], i, n;
 printf("\nEnter no. of elements: "); 
 scanf("%d", &n);
 printf("\nEnter the elements: \n");
 for (i=0; i<n; i++)
  scanf ("%d", &a[i]);
 printf("\nUnsorted elements: \n");
 printarray(a,n);
 selection_short(a,n);
 printf("\nSorted elements: \n");
 printarray(a,n);
}
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void selection_short(int a[],int n)
{
	int i,k,j;
	for(i=1;i<n;i++)
	{
		k=a[i];
		for(j=i-1;j>=0&&k<a[j];j--)
			a[j+1]=a[j];
		a[j+1]=k;
	}
}
