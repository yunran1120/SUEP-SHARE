/* c4-2-7.c */
#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c,t,k;
	float s,p;
	printf("请输入三角形的三个边长：");
	scanf("%d%d%d",&a,&b,&c);
	p=(a+b+c)/2.0;
	if (a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	if (a>c)
	{
		t=a;
		a=c;
		c=t;
	}
	if (b>c)
	{
		t=b;
		b=c;
		c=t;
	}
	if (a+b>c)
	{
		if(a==b &&b==c) k=1; //等边
		else if(a==b || b==c) k=2; //等腰
		else if(a*a+b*b==c*c) k=3; //直角
		else k=4;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
	}
	else k=0;
	switch(k)
	{
		case 0:
			printf("不能构成三角形。");
			break;
		case 1:
			printf("三角形类型为等边三角形，其面积为：%f",s);
			break;
		case 2:
			printf("三角形类型为等腰三角形，其面积为：%f",s);
			break;
		case 3: 
			printf("三角形类型为直角三角形，其面积为：%f",s);
			break;
		case 4: 
			printf("三角形类型为一般三角形，其面积为：%f",s);
			break;
	}
	return 0;
}