/* c9-2-6.c */
#include <stdio.h>
int main()
{
	char a[100]={0};
	int big=0,small=0,num=0,space=0,other=0;
	int i;
	printf("请输入一行文字(不超过 80 个字符)：");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='A'&&a[i]<='Z') big++;
		else if(a[i]>='a'&&a[i]<='z') small++;
		else if(a[i]>='0'&&a[i]<='9') num++;
		else if(a[i]==' ') space++;
		else other++;
	}
	printf("大写字母共%d个，小写字母共%d个，数字共%d个，空格共%d个，其他字符共%d个",big,small,num,space,other);
	return 0;
}