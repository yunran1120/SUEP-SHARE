/* c6-2-10.c */
#include <stdio.h>
int main()
{
	int n = 1;
	while(1)
	{
		if(n%2==1 && n%3==2 && n%5==4 && n%6==5 && n%7==0)
			{
				printf("共有%d阶",n);
				break;
			}
		else n++;
	}
	return 0;
}