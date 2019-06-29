#include<stdio.h>
int main()
/*{
struct xx
{
//int x=3;
char name[5]="hello";
};
struct xx s;
//printf("%d",sx);
printf("%s",s.name);
}*/
/*{
printf("\nab");
printf("\bsi");
printf("\rha");
}*/
/*{
char far *farther,*farthest;
printf("%d..%d",sizeof(farther),sizeof(farthest));
}*/
/*{
int i=400,j=300;
printf("%d..%d");
}*/
{
static char names[5][20]={"pascal","ada","cobol","fortran","perl"};
int i;
char *t;
t=names[3];
names[3]=names[4];
names[4]=t;
for (i=0;i<=4;i++)
printf("%s",names[i]);
}
