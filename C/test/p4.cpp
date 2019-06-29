#include<stdio.h>

int main(){

    register int a,b;

    int c;

    scanf("%d%d",&a,&b);

    c=~a + ~b + ++a + b++;

    printf(" %d",c);

    return 0;

}
