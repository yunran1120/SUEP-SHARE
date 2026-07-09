/* c10-2-4.c */
#include <stdio.h>
long func(long m)
{
	long k=1;
	do
	{
		k=k*(m%10);
		m/=10;
	}while(m!=0);
	return (k);
}

int main()
{
	long n;
	printf("请输入整数n:");
	scanf("%ld",&n);
	printf("整数%ld 的各位之积为:%ld\n",n,func(n));
}