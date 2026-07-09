/* c9-2-2.c */
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[80]="This Is a ",str2[80]="c Program";
	printf("String1 is: %s\n",str1);
	printf("String2 is: %s\n",str2);
	printf("The length of str1 is: %d\n",strlen(str1)); /*使用 strlen 函数实现*/
	printf("The length of str2 is: %d\n", strlen(str2));
	if(strcmp(str1,str2)>0)
		printf("The max is:%s\n",str1);
	else
		printf("The max is:%s\n",str2);
	strcat(str1,str2);
	printf("Result is: %s\n",str1);
	return 0;
}