/* c9-2-5.c */
#include <stdio.h>

int main()
{
	char a[100];
	int b[100];
	int i,j=0,m;
	int flag=0;
	char ch;
	printf("请输入字符串：");
	gets(a);
	printf("请输入要查找的字符：");
	ch=getchar();
	for(i=0;a[i]!='\0';i++)
	{
		if(ch==a[i])
		{
			b[j]=i;
			j++;
			flag=1;
		}
	}
	if(flag==0)
		printf("字符串中不包含字符 '%c'\n", ch);
	else
    {
        printf("字符 '%c' 出现了 %d 次，位置分别为：", ch, j);
        for(m = 0; m < j; m++)
            printf("%d ", b[m]);
        printf("\n");
    }
    return 0;
}