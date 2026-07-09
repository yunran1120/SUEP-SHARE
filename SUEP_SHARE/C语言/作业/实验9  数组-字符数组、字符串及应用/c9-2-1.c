/* c9-2-1.c */
#include <stdio.h>
int main()
{
	char s[10];
	int i;
	int n=0;
	printf("请输入数字字符串：");
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]<'0' || s[i]>'9')
		{
			printf("输入非法字符\n");
			return 1;	
		}
		else
			n=n*10+(s[i] - '0');
		}
		printf("n=%ld\n",n);
		return 0;
}