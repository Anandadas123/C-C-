#include <stdio.h>
void f(int *p, int *g){
p=g;
*p= 9;
}
int i=0, j=1;
int main ( ){
	
f(&i,&j);
printf("%d%d \n", i, j);
return 0;
}

