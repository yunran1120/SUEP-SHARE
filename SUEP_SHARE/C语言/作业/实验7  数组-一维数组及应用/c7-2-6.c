/*  c7-2-6.c  */
#include <stdio.h>
int main()
{
	int a[10]={1,5,12,36,78,115,225,341,489,796};
	int sum=0,i;
	for(i=0;i<10;i+=2)
	{
		sum+=a[i];
	}
	printf("下标为偶数的元素之和为%d",sum);
	return 0;
}