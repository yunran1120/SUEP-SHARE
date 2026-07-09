#include <stdio.h>
int main()
{
	int m,s,temp;
	scanf("%d",&m);
	for (temp = m; temp != 0; temp /= 10)
    	s = s * 10 + temp % 10;
	printf("%d",s);
	return 0;
}