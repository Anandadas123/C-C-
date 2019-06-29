#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int  main()
{
	char flag='t',str1[30],str2[30];
	int left,right,len;
	printf("\n enter the string");
	gets(str1);
	len=strlen(str1);
	/*left=0;
	right=len-1;
	while(left<right&&flag=='t')
	{
		if(str[left]==str[right]);
		else
		flag='f';
		left++;
		right--;
	}
	if(flag=='t')
	printf("\n string are palindrom");
	else
	printf("\n string are not palindrom");
	*/
	printf("\n enter the string");
	gets(str2);
	len=strlen(str2);	
    strstr(str1,str2);
//	strncmp(str1,str2,5);
//	if(strncmp(str1,str2,5)==NULL)
	if(strstr(str1,str2)==NULL)
		printf("substring is not found");
	else
		printf("str2 is a substring of str1");
}
