/*  c7-2-9.c  */
#include <stdio.h>
int main()
{
	int a[10]={6,9,12,9,8,20,9,6,15,5};
	int x,i,j;
	int n=10;
	printf("Please input x:");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(x==a[i])
		{
			for(j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			n--;
			i--;
		}
	}
	printf("新数组为：");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}