/* c12-2-4.c */
#include <stdio.h>
int amax(int *a,int n);
int main()
{
	int a[10],i;
	printf("please input array a:\n");
	for(i=0;i<10;i++)
		scanf("%d",a+i);
	printf("MAX=%d\n",amax(a,10));
	return 0;
}

int amax(int *a,int n)
{
	int max,i;
	max=*a;
	for(i=1;i<n;i++)
		if(*(a+i)>max) max=*(a+i);
	return max;
}