#include <stdio.h>
#define MAXN 100
int main()
{
    int a[MAXN][MAXN];
    int n, i, j;
    int symmetric = 1;
    printf("请输入方阵阶数 N (1 <= N <= %d): ", MAXN);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN)
	{
        printf("阶数输入非法！\n");
        return 0;
    }
    printf("请按行输入 %d×%d 个整数：\n", n, n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n && symmetric; ++i)
        for (j = i + 1; j < n; ++j)
            if (a[i][j] != a[j][i])
			{
                symmetric = 0;
                break;
            }
    if (symmetric)
        printf("该方阵是对称矩阵。\n");
    else
        printf("该方阵不是对称矩阵。\n");
    return 0;
}