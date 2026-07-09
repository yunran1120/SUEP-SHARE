/* c10-2-1.c */
#include <stdio.h>
int fac(int n)
{
	int i;
	int t=1;
	for(i=1;i<=n;i++)
		t=i*fac(i-1);
	return t;
}

int main()
{
	int m,n,t,cmn;
	printf("please enter m and n:");
	scanf("%d%d",&m,&n);
	if(m<n)
	{
		t=m;m=n;n=t;
	}
	if(m<0||n<0)
	{
		printf("input error!");
		return 0;
	}
	cmn=fac(m)/fac(n)/fac(m-n);
	printf("C(%d,%d)=%d\n",m,n,cmn);
	return 0;
}