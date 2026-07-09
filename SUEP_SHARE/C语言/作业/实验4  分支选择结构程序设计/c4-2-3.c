/* c4-2-3.c */
#include <stdio.h>
int main( )
{
	float x,y;
	printf("请输入 x 的值：");
	scanf("%f",&x);
	if (x>=0)
		y=x+1;
	else
		y=x-1;
	printf("y=%.3f\n",y);
	return 0;
}