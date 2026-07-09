/* c4-2-8.c */
#include <stdio.h>
int main()
{
	float t,w,h;
	int k;
	printf("请输入身高(m)：");
	scanf("%f",&h);
	printf("请输入体重(kg)：");
	scanf("%f",&w);
	t=w/(h*h);
	if (t<18.0) k=1;
	else if (t>=18.0 && t<25.0) k=2;
	else if (t>=25.0 && t<27.0) k=3;
	else k=4;
	printf("您的体型为：");
	switch(k)
	{
		case 1: printf("低体重");break;
		case 2: printf("正常体重");break;
		case 3: printf("超重体重");break;
		case 4: printf("肥胖");break;
	}
	return 0;
}