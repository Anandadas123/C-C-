#include<stdio.h>

int main(){

    static int a[5][2][3]={8,5};

    int i=-1;

    int d;

    d=a[i++][++i][++i];

    printf("%d",d);

    return 0;

}
