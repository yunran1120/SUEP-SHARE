/* c4-2-6.c */
#include <stdio.h>
int main( )
{
	int a,b,gewei,shiwei,baiwei,qianwei,wanwei,weishu;
	printf("请输入一个不多于5位的正整数：");
	scanf("%d",&a);
    if (a < 0 || a > 99999)
    {
        printf("输入错误！请输入1~5位的正整数！\n");
        return 0;
    }
	gewei=a%10;
	shiwei=(a/10)%10;
	baiwei=(a/100)%10;
	qianwei=(a/1000)%10;
	wanwei=(a/10000)%10;
	if (wanwei!=0) weishu=5;
	else if (qianwei!=0) weishu=4;
	else if (baiwei!=0) weishu=3;
	else if (shiwei!=0) weishu=2;
	else weishu=1;
	printf("这个数是%d位数",weishu);
	printf("每位数分别是：");
	switch(weishu)
	{
		case 1: printf("%d\n",gewei);break;
		case 2: printf("%d %d\n",shiwei,gewei);break;
		case 3: printf("%d %d %d\n",baiwei,shiwei,gewei);break;
		case 4: printf("%d %d %d %d\n",qianwei,baiwei,shiwei,gewei);break;
		case 5: printf("%d %d %d %d %d\n",wanwei,qianwei,baiwei,shiwei,gewei);break;
	}
	printf("逆序打印的结果为：");
	switch(weishu)
	{
		case 1: printf("%d\n",gewei);break;
		case 2: printf("%d %d\n",gewei,shiwei);break;
		case 3: printf("%d %d %d\n",gewei,shiwei,baiwei);break;
		case 4: printf("%d %d %d %d\n",gewei,shiwei,baiwei,qianwei);break;
		case 5: printf("%d %d %d %d %d\n",gewei,shiwei,baiwei,qianwei,wanwei);break;
	}
	return 0;
}
