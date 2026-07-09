/* c6-2-5.c */
#include <stdio.h>
int main()
{
	int i,j,t;
	double sum;
	for (i=1,sum=0;i<=20;i++)
	{
		t=1;
		for(j=1;j<=i;j++)
			t=t*j;
		sum=sum+1.0/t;
	}
	printf("%lf",sum);
	return 0;
}