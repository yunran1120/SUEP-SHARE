#include <stdio.h>
#define MAX 50
int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int m, p, n;
    int i, j, k;
    printf("请输入矩阵 A 的行数 m 和列数 p：");
    scanf("%d %d", &m, &p);
    if (m <= 0 || p <= 0 || m > MAX || p > MAX)
	{
        printf("A 的维度非法！\n");
        return 0;
    }
    printf("请按行输入 A 的 %d×%d 个整数：\n", m, p);
    for (i = 0; i < m; ++i)
        for (j = 0; j < p; ++j)
            scanf("%d", &A[i][j]);
    printf("请输入矩阵 B 的行数 p 和列数 n：");
    scanf("%d %d", &p, &n);
    if (p <= 0 || n <= 0 || p > MAX || n > MAX)
	{
        printf("B 的维度非法！\n");
        return 0;
    }
    printf("请按行输入 B 的 %d×%d 个整数：\n", p, n);
    for (i = 0; i < p; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &B[i][j]);
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
		{
            int sum = 0;
            for (k = 0; k < p; ++k)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    printf("乘积矩阵 C = A × B (%d×%d)：\n", m, n);
    for (i = 0; i < m; ++i)
	{
        for (j = 0; j < n; ++j)
            printf("%6d", C[i][j]);
        putchar('\n');
    }
    return 0;
}