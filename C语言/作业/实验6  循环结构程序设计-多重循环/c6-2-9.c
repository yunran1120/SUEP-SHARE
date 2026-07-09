/* c6-2-9.c */
#include <stdio.h>
double f(double x)
{
    return x * x * x - x * x - 1;
}
int main()
{
	float low=0.0,high=3.0,mid,eps=1e-6;
	if (f(low)*f(high)>0)
	{
		printf("不保证有根。");
		return 1;	
	}
	while (high - low > eps)
	{
		mid=(low+high)/2.0;
		if (f(mid) == 0.0)
            break;
        if (f(low) * f(mid) < 0)
            high = mid;
        else
            low = mid;
	}
	mid=(low+high)/2.0;
	printf("近似根为：%f",mid);
    return 0;
}