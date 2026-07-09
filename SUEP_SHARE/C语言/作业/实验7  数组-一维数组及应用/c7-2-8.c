/*  c7-2-8.c  */
#include <stdio.h>
int main()
{
    int a[10] = {6, 9, 12, 15, 19, 23, 45, 67, 89, 98};
    int x, i, n = 10;
    int old_n = n;
    printf("请输入x：");
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            n--;                     
            i--;                     
            break;                   
        }
    }
    if (n < old_n)        
    {
        printf("新数组为：");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    else
    {
        printf("数组中不存在 %d\n", x);
    }
    return 0;
}