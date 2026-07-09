/* c10-2-8.c */
#include <stdio.h>
int GCD(int m,int n);

int main()
{
	int m,n,yue;
	printf("please enter m and n : ");
	scanf("%d%d",&m,&n);
	yue=GCD(m,n);
	printf("最大公约数为%d",yue);
	return 0;
}

int GCD(int m,int n)
{
	int t,i,temp;
	if(m>n)
	{
		t=m;m=n;n=t;
	}
	while(n!=0)
	{
		temp=m%n;
		m=n;
		n=temp;
	}
	return m;
}