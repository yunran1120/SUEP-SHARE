/* c3-1-3.c */
#include <stdio.h>
int main()
{
	float fa,fb,fc,fsum;
	double d;
	fa=3141.592678;
	fb=6.026e-27;
	fsum=fa+fb;
	d=31415926.78;
	printf("float类型数据的打印结果：\n");
	printf("fa=%f\t fb=%f\t fsum=%7.2\n",fa,fb,fsum);
	printf("fa=%e\t fb=%e\t fsum=%e\n",fa,fb,fsum);
	printf("double类型数据的打印结果：\n");
	printf("d=%lf, d=%e\n",d,d);
	return 0;
}