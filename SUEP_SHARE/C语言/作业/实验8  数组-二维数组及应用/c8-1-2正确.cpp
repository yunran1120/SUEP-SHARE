#include <stdio.h>
int main()
{
    int a[3][3] = {10,20,30,40,50,60};
    int i, j;
    printf("输出数组 a 中所有元素的值:\n");
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
            printf("%5d", a[i][j]);
        printf("\n");
    }
    return 0;
}