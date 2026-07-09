/* c6-2-11.c */
#include <stdio.h>

int main()
{
    int n, zhiyinzi;
    printf("请输入一个正整数 n：");
    scanf("%d", &n);
    printf("%d 的所有质因子为：", n);

    zhiyinzi = 2;
    while (n > 1)
    {
        if (n % zhiyinzi == 0)
        {
            printf("%d", zhiyinzi);
            n = n / zhiyinzi;
            if (n > 1)
                printf("，");
        }
        else
        {
            zhiyinzi++; 
        }
    }
    printf("\n");
    return 0;
}