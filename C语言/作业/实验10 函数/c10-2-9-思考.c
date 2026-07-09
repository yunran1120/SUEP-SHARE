/* c10-2-9.c */
#include <stdio.h>
int convert(int m, int  binary[]);

int main()
{
	int m,arr[100];
	int length,num;
	printf("请输入待转换的十进制数：");
	scanf("%d",&m);
	length=convert(m,arr);
	printf("%d的二进制为：",m);
	for(int i=length-1;i>=0;i--)
	{
		printf("%x",arr[i]);
	}
	return 0;
}


int convert(int m, int  binary[])
{
	int temp=1;
	int i=m,j=1,k=0;
	while(j!=0)
	{
		j=i/16;
		binary[k]=i%16;
		i=j;
		k++;
	}
	return k;
}
