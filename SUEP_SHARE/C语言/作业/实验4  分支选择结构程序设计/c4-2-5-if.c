/* c4-2-5-if.c */
#include <stdio.h>
int main( )
{
	int mark;
	printf("请输入考试成绩：");
	scanf("%d",&mark);
	if (mark < 0 || mark > 100) printf("输入错误！成绩必须在0~100之间！\n");return 0;
	else if(mark>=90) printf("A级");
	else if(mark>=80) printf("B级");
	else if(mark>=70) printf("C级");
	else if(mark>=60) printf("D级");
	else printf("E级");
	return 0;
}
