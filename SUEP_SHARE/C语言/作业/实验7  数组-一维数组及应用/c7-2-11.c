/*  c7-2-11.c  */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define throws 6000
int main()
{
	int face[6] = {0};
	int i,point;
	srand(time(NULL));
	for(i=0;i<throws;i++)
	{
		point = rand()%6+1;
		face[point-1]++;
	}
	printf("每个点数出现概率：\n");
	for(i=1;i<=6;i++)
	{
		printf("%d点出现%d次，概率为%f%%\n",i,face[i-1],face[i-1]*100.0/throws);
	}
	return 0;
}