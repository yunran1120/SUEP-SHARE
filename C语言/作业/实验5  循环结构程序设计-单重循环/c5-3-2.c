/* c5-3-2.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double total_money;
    int num;
    int i;
    int *money_fen;
    int remain_fen;
    int rand_max;
    FILE *fp;
    printf("请输入红包总金额（元）：");
    scanf("%lf", &total_money);
    printf("请输入红包个数：");
    scanf("%d", &num);
    if (num <= 0 || total_money < 0.01) {
        printf("输入无效！\n");
        return 1;
    }
    int total_fen = (int)(total_money * 100 + 0.5);
    if (total_fen < num) {
        printf("总金额不足，每个红包至少0.01元！\n");
        return 1;
    }
    money_fen = (int *)malloc(num * sizeof(int));
    if (money_fen == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }
    srand((unsigned int)time(NULL));
    remain_fen = total_fen;
    for (i = 0; i < num - 1; i++) {
        rand_max = remain_fen - (num - i);
        if (rand_max < 1) rand_max = 1;
        int r = rand() % rand_max + 1;
        money_fen[i] = r;
        remain_fen -= r;
    }
    money_fen[num - 1] = remain_fen;
    fp = fopen("red_packet.txt", "w");
    if (fp == NULL) {
        printf("无法创建文件 red_packet.txt！\n");
        free(money_fen);
        return 1;
    }

    fprintf(fp, "红包总金额：%.2f 元\n", total_money);
    fprintf(fp, "红包个数：%d\n", num);
    fprintf(fp, "各红包金额（元）：\n");
    for (i = 0; i < num; i++) {
        fprintf(fp, "%.2f  ", money_fen[i] / 100.0);
        if ((i + 1) % 5 == 0) fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    fclose(fp);
    printf("\n红包已生成，结果保存到 red_packet.txt\n");
    printf("总金额：%.2f 元，个数：%d\n", total_money, num);
    printf("各红包金额：");
    for (i = 0; i < num; i++) {
        printf("%.2f  ", money_fen[i] / 100.0);
    }
    printf("\n");
    free(money_fen);
    return 0;
}