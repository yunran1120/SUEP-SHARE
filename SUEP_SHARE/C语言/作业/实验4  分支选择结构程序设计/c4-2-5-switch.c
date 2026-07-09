/* c4-2-5-SWITCH.c */
#include <stdio.h>
int main( )
{
	int mark;
	printf("请输入考试成绩：");
	scanf("%d",&mark);
	if (mark < 0 || mark > 100)
    {
        printf("输入错误！成绩必须在0~100之间！\n");
        return 0;
	}
	switch(mark/10)
	{
		case 10:printf("A级");break;
		case 9:printf("A级");break;
		case 8:printf("B级");break;
		case 7:printf("C级");break;
		case 6:printf("D级");break;
		default:printf("E级");
	}
	return 0;
}
