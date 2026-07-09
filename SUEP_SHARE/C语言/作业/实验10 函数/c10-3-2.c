/* c10-3-2.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 200

void input(int bigint[]);
void output(int bigint[]);
void add(int bigint1[], int bigint2[], int bigint3[]);
int  cmp_bigint(int bigint1[], int bigint2[]);
void sub(int bigint1[], int bigint2[], int bigint3[]);
void multiply(int bigint1[], int bigint2[], int bigint3[]);

void adjust(int bigint[]);

int main(void) {
    int bigint1[MAX_DIGITS + 1] = {0};
    int bigint2[MAX_DIGITS + 1] = {0};
    int bigint3[MAX_DIGITS * 2 + 1] = {0};
    int choice;

    do {
        printf("\n========== 大整数运算菜单 ==========\n");
        printf("1. 输入第一个大整数\n");
        printf("2. 输入第二个大整数\n");
        printf("3. 输出两个大整数\n");
        printf("4. 大整数加法 (bigint1 + bigint2)\n");
        printf("5. 大整数减法 (bigint1 - bigint2)\n");
        printf("6. 大整数乘法 (bigint1 * bigint2)\n");
        printf("7. 比较大整数\n");
        printf("0. 退出\n");
        printf("请选择(0~7): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: 
                printf("请输入第一个大整数: ");
                input(bigint1);
                break;
            case 2:
                printf("请输入第二个大整数: ");
                input(bigint2);
                break;
            case 3:
                printf("bigint1 = ");
                output(bigint1);
                printf("bigint2 = ");
                output(bigint2);
                break;
            case 4:
                add(bigint1, bigint2, bigint3);
                printf("bigint1 + bigint2 = ");
                output(bigint3);
                break;
            case 5:
                if (cmp_bigint(bigint1, bigint2) < 0) {
                    printf("错误：被减数小于减数，结果为负，请重新输入或交换操作数。\n");
                } else {
                    sub(bigint1, bigint2, bigint3);
                    printf("bigint1 - bigint2 = ");
                    output(bigint3);
                }
                break;
            case 6:
                multiply(bigint1, bigint2, bigint3);
                printf("bigint1 * bigint2 = ");
                output(bigint3);
                break;
            case 7:
                {
                    int res = cmp_bigint(bigint1, bigint2);
                    printf("比较结果: ");
                    if (res > 0)
                        printf("bigint1 > bigint2\n");
                    else if (res == 0)
                        printf("bigint1 == bigint2\n");
                    else
                        printf("bigint1 < bigint2\n");
                }
                break;
            case 0:
                printf("程序退出。\n");
                break;
            default:
                printf("无效选项，请重新选择。\n");
        }
    } while (choice != 0);

    return 0;
}

void input(int bigint[]) {
    char str[MAX_DIGITS + 2];
    int i, len;
    fgets(str, MAX_DIGITS + 2, stdin);
    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);

    if (len == 0) {
        printf("错误：未输入任何数字，程序退出。\n");
        exit(1);
    }
    for (i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            printf("错误：包含非法字符 '%c'，程序退出。\n", str[i]);
            exit(1);
        }
    }
    if (len > MAX_DIGITS) {
        printf("错误：输入数字超过最大位数 %d，程序退出。\n", MAX_DIGITS);
        exit(1);
    }

    i = 0;
    while (i < len - 1 && str[i] == '0')
        i++;
    int valid_len = len - i;
    if (valid_len == 0) valid_len = 1;

    bigint[0] = valid_len;

    int j;
    for (j = 1; j <= valid_len; j++) {
        bigint[j] = str[len - j] - '0';
    }
}

void output(int bigint[]) {
    int i;
    for (i = bigint[0]; i >= 1; i--) {
        printf("%d", bigint[i]);
    }
    printf("\n");
}

void add(int bigint1[], int bigint2[], int bigint3[]) {
    int len1 = bigint1[0];
    int len2 = bigint2[0];
    int max_len = (len1 > len2) ? len1 : len2;
    int i, carry = 0, sum;

    for (i = 1; i <= max_len; i++) {
        int digit1 = (i <= len1) ? bigint1[i] : 0;
        int digit2 = (i <= len2) ? bigint2[i] : 0;
        sum = digit1 + digit2 + carry;
        bigint3[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        bigint3[i] = carry;
        bigint3[0] = max_len + 1;
    } else {
        bigint3[0] = max_len;
    }

    adjust(bigint3);
}

int cmp_bigint(int bigint1[], int bigint2[]) {
    int len1 = bigint1[0];
    int len2 = bigint2[0];

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    int i;
    for (i = len1; i >= 1; i--) {
        if (bigint1[i] > bigint2[i]) return 1;
        if (bigint1[i] < bigint2[i]) return -1;
    }
    return 0;
}

void sub(int bigint1[], int bigint2[], int bigint3[]) {
    int len1 = bigint1[0];
    int len2 = bigint2[0];
    int i, borrow = 0, diff;

    for (i = 1; i <= len1; i++) {
        int digit1 = bigint1[i];
        int digit2 = (i <= len2) ? bigint2[i] : 0;
        diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        bigint3[i] = diff;
    }

    bigint3[0] = len1;
    adjust(bigint3);
}

void multiply(int bigint1[], int bigint2[], int bigint3[]) {
    int len1 = bigint1[0];
    int len2 = bigint2[0];
    int temp[MAX_DIGITS * 2 + 1] = {0};
    int i, j;

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            temp[i + j - 1] += bigint1[i] * bigint2[j];
        }
    }

    int max_len = len1 + len2;
    int carry = 0;
    for (i = 1; i <= max_len; i++) {
        int sum = temp[i] + carry;
        temp[i] = sum % 10;
        carry = sum / 10;
    }

    int result_len = max_len;
    while (result_len > 1 && temp[result_len] == 0)
        result_len--;

    bigint3[0] = result_len;
    for (i = 1; i <= result_len; i++) {
        bigint3[i] = temp[i];
    }
}

void adjust(int bigint[]) {
    int len = bigint[0];
    while (len > 1 && bigint[len] == 0)
        len--;
    bigint[0] = len;
}