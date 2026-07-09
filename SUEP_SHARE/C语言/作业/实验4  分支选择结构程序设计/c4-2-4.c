/* c4-2-4.c */
#include <stdio.h>
int main( )
{
	float d1,d2;
	char op;
	printf("输入 d1 op d2： ");
	scanf ("%f%c%f",&d1,&op,&d2);
	switch(op)
	{
		float temp;
		case '+': temp=d1+d2;printf ("%.2f %c %.2f=%.2f",d1,op,d2,temp);break;
		case '-': temp=d1-d2;printf ("%.2f %c %.2f=%.2f",d1,op,d2,temp);break;
		case '*': temp=d1*d2;printf ("%.2f %c %.2f=%.2f",d1,op,d2,temp);break;
		case '/': temp=d1/d2;printf ("%.2f %c %.2f=%.2f",d1,op,d2,temp);break;
		default:printf ("错误！\n");
	}
	return 0;
}
