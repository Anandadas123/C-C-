#include<stdio.h>
#include<conio.h>

void merge_short(int a[],int,int);
void merge(int a[],int low1,int up1,int up2);

int main()
{
	int i,n;
	printf("\n how many no you want to merg_short::");
	scanf("%d",&n);
	int a[n];
	printf("\n enter the element::");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge_short(a,0,n-1);
	printf("\n shorted array is::");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void merge_short(int a[],int low,int up)
{
	int mid;
	
	if(low<up)
	{
		mid=(low+up)/2;
		merge_short( a,low, mid);
		merge_short( a,mid+1, up);
		merge(a,low,mid,up);	
	}
}
 void merge(int a[],int low1,int up1,int up2)
{
	int i=low1;
	int j=up1+1;
	int k=0;
	int temp[up2-low1+1];
	while((i<=up1)&&(j<=up2))
	{
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else	
			temp[k++]=a[j++];
	}
	while(i<=up1)
		temp[k++]=a[i++];
	while(j<=up2)
		temp[k++]=a[j++];
	 for(i= 0;i <k; i++)
        {
                a[i+low1] = temp[i];
                printf("%d ",a[i]);
        }
        printf("\n");
}


