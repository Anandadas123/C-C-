#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("insert value");
	scanf("%d",&n);
	int* p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	p[i]=i+1;
	free(p);
	p[3]=8;
	for(i=0;i<n;i++)
	printf("%d ",p[i]);
}
