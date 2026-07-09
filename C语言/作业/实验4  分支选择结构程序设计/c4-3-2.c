/* c4-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a,b;
	int op;
	int result;
	int input;
	int temp;
	char k='+';
	srand(time(NULL));
	a=rand()%100;
	b=rand()%100;
	op=rand()%2; //0为+，1为-
	if (op==1) k='-';
	if (op==1 && a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if (op==0) result=a+b;
	else result=a-b;
	printf("题目：%d %c %d = ?\n请输入答案：",a,k,b);
	scanf("%d",&input);
	if (input==result) printf("答案正确！");
	else printf("答案错误！正确答案是：%d",result);
	return 0;
}