/* c10-2-7.c */
#include<stdio.h>
#define N 10
int bin_search(int arr[],int x,int low,int high)
{
	int mid;
	while(high>=low)
	{
		mid=(low+high)/2;
		if(x==arr[mid]) return mid;
		else
			if(x<arr[mid]) high=mid-1;
			else
				low=mid+1;
	}
	return -1;
}

int main()
{
	int a[N]={10,20,30,40,50,60,70,80,90,100};
	int x,find_x,i;
	printf("array a:\n");
	for(i=0;i<N;i++)
		printf("%5d",a[i]);
	printf("\n");
	printf("please input x:");
	scanf("%d",&x);
	find_x=bin_search(a,x,1,N);
	if(find_x==-1)
		printf("没找到 %d\n",x);
	else
		printf("找到了，%d 的下标为%d\n",x,find_x);
	return 0;
}