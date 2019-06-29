#include<stdio.h>

int main(){

    int a[]={10,20,30,40};

    int i=3,x;

    x=1*a[--i]+2*a[--i]+3*a[--i];

    printf("%d",x);

    return 0;

}
