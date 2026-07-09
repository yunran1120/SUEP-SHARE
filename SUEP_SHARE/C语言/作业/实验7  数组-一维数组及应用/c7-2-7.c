/*  c7-2-7.c  */
#include <stdio.h>
int main()
{
	int a[20]={6,9,12,15,19,23,45,67,89,98};
	int n=10;
	int x,i;
	printf("Please input x:");
	scanf("%d",&x);
	for(i=n-1;i>=0 && x<a[i];i--)
	{
		a[i+1] = a[i];
	}
	a[i+1]=x;
	n++;
	printf("新数组为：");
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}