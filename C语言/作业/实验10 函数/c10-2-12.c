/* c10-2-12.c */
#define N 3
#include <stdio.h>
void transposition(int x[N][N]);

int main()
{
	int arr[N][N],i,j;
	printf("请输入3x3矩阵:");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("原3x3矩阵:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	transposition(arr);
	printf("转制后的3x3矩阵:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void transposition(int x[N][N])
{
	int temp;
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			temp=x[i][j];
			x[i][j]=x[j][i];
			x[j][i]=temp;
		}
	}
}