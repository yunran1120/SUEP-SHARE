/* c6-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long long n, i, count = 0;
    double x, y, pi;
    printf("请输入随机点的数量 n (建议大于 100000): ");
    scanf("%lld", &n);
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0)
            count++;
    }
    pi = 4.0 * count / n;
    printf("\n随机点数: %lld\n", n);
    printf("落入圆内点数: %lld\n", count);
    printf("估算的圆周率 π ≈ %.10f\n", pi);
    return 0;
}