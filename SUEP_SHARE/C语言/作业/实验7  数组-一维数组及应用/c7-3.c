/* c7-3.c  */
#include <stdio.h>
#include <string.h>
#define MAX 200
int read_num(int num[], char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        num[i] = str[len - 1 - i] - '0';
    return len;
}
void print_num(int num[], int len)
{
    int i = len - 1;
    while (i > 0 && num[i] == 0)
        i--;
    for (; i >= 0; i--)
        printf("%d", num[i]);
}
int main()
{
    char strA[MAX + 10], strB[MAX + 10];
    int A[MAX] = {0}, B[MAX] = {0}, C[MAX + 1] = {0};
    int lenA, lenB, lenC, carry = 0;
    printf("请输入大整数 A: ");
    scanf("%s", strA);
    printf("请输入大整数 B: ");
    scanf("%s", strB);
    lenA = read_num(A, strA);
    lenB = read_num(B, strB);
    lenC = (lenA > lenB) ? lenA : lenB;
    for (int i = 0; i < lenC; i++)
    {
        int sum = A[i] + B[i] + carry;
        C[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry)
        C[lenC++] = carry;
    printf("A + B = ");
    print_num(C, lenC);
    printf("\n");
    return 0;
}