/* c9-2-8.c */
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100];
	char str2[100];
	int i;
	int len1,len2;
	printf("请输入第一个字符串：");
	gets(str1);
	printf("请输入第二个字符串：");
	gets(str2);
	len1=strlen(str1);
	len2=strlen(str2);
	for(i=0;i<len2;i++)
	{
		str1[len1+i]=str2[i];
	}
	str1[len1+len2]='\0';
	printf("the catenated string is %s",str1);
	return 0;
}