/* c10-2-13.c */
#include <stdio.h>
#include <stdlib.h>
double p(int n,double x);
int main()
{
	int n;
	double x,result;
	printf("请输入n与x：");
	scanf("%d%lf",&n,&x);
	result=p(n,x);
	printf("结果为：%lf",result);
	return 0;
}

double p(int n,double x)
{
	if(n==0) return 1;
	else if(n==1) return x;
	else if(n>1) {
		double j;
		j=((2*n-1)*x*p(n-1,x)-(n-1)*p(n-2,x))/n;
		return j;
	}
	else {
	printf("n输入有误");
	exit(-1);	
	}
}