/* c9-2-7.c */
#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	char t[100];
	int i;
	int length;
	printf("请输入字符串：");
	gets(s);
	length=strlen(s);
	for(i=0;s[i]!='\0';i++)
	{
		t[i]=s[length-i-1];
	}
	t[length] = '\0';
	printf("逆序后的字符串：%s\n", t);
	return 0;
}