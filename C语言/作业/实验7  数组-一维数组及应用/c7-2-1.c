/*  c7-2-1.c  */
#include <stdio.h>
int main()
{
    int i, a[10];
    for (i = 1; i <= 10; i++)
    /**************found************/
        a[i-1]=i;
    printf("数组 a:\n");
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
    for (i = 0; i < 5; i++)         // 对折数组 a 中元素
    /**************found************/
        a[i+5]=a[4-i];
    printf("对折后数组 a：\n");
    for (i = 0; i < 10; i++)
        printf("%5d", a[i]);
    printf("\n");
    return 0;
}