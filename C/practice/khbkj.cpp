#include <stdio.h>

#define   message_for(a, b)  printf(a##b )

int main(void)
{ int st=8;
   message_for(s,t);
   return 0;
}
