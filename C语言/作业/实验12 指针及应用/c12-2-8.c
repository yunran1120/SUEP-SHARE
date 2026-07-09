/* c12-2-8.c */
#include <stdio.h>

void count_chars(char *str, int *upper, int *lower, int *digit, int *other);

int main()
{
    char str[100];
    int upper, lower, digit, other;

    printf("请输入一个字符串：");
    gets(str);

    count_chars(str, &upper, &lower, &digit, &other);

    printf("大写	字母：%d\n", upper);
    printf("小写字母：%d\n", lower);
    printf("数    字：%d\n", digit);
    printf("其他字符：%d\n", other);

    return 0;
}

void count_chars(char *p, int *upper, int *lower, int *digit, int *other)
{
    *upper = *lower = *digit = *other = 0;
    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            (*upper)++;
        else if (*p >= 'a' && *p <= 'z')
            (*lower)++;
        else if (*p >= '0' && *p <= '9')
            (*digit)++;
        else
            (*other)++;
        p++;
    }
}