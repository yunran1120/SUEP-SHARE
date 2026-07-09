/* c10-2-10.c */
#include <stdio.h>
#include <string.h>
void fun(char str1[],char str2[]);

int main()
{
	char a[100],b[100];
	int length_a,length_b,i;
	printf("请输入字符串：");
	gets(a);
	length_a=strlen(a);
	printf("当前字符串：");
	for(i=0;i<length_a;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	fun(a,b);
	length_b=strlen(b);
	printf("新字符串：");
	for(i=0;i<length_b;i++)
	{
		printf("%c",b[i]);
	}
	return 0;
}

void fun(char str1[],char str2[])
{
	int len=strlen(str1)/2;
	for(int i=0;i<len+1;i++)
	{
		str2[i]=str1[i*2];
	}
}