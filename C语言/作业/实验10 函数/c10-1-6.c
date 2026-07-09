/* c10-1-6.c */
#include <stdio.h>
int m,n;
void swap()
{
	int t;
	t=m;m=n;n=t;
	printf("function swap:\n");
	printf("m=%d,n=%d\n",m,n);
}

int main()
{
	int m,n;
	printf("please input m and n:");
	scanf("%d%d",&m,&n);
	swap();
	printf("function main:\n");
	printf("m=%d,n=%d\n",m,n);
	return 0;
}