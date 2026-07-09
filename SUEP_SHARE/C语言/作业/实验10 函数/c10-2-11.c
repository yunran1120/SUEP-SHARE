/* c10-2-11.c */
#include <stdio.h>
void select_sort(int arr[],int n);

int main()
{
	int a[100],num,i;
	printf("请输入待排序的内容的长度：");
	scanf("%d",&num);
	printf("请输入待排序的内容：");
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}
	select_sort(a,num);
	printf("排序后的内容：");
	for(i=0;i<num;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}

void select_sort(int arr[],int n)
{
	int min,i,j,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
}