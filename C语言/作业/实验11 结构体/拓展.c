/* bus_system.c 班车预约系统 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000   /* 最多存储的预约记录数 */

/* 日期结构体 */
typedef struct {
    int year;
    int month;
    int day;
} Date;

/* 预约记录结构体 */
typedef struct {
    char No[9];           /* 8位学号或工号 */
    char name[20];        /* 姓名 */
    int trav_line_no;     /* 班车线路编号 1~10 */
    Date order_date;      /* 预约日期 */
} bus_order;

/* 函数声明 */
int read_data(bus_order *orders, int *count);
void order(void);
void query(void);

int main(void) {
    int choice;

    while (1) {
        printf("\n===== 班车预约系统 =====\n");
        printf("1. 预约班车\n");
        printf("2. 查询预约信息\n");
        printf("3. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);
        getchar();  /* 吸收换行符 */

        switch (choice) {
            case 1:
                order();
                break;
            case 2:
                query();
                break;
            case 3:
                printf("感谢使用，再见！\n");
                return 0;
            default:
                printf("无效选择，请重新输入。\n");
        }
    }
}

/**
 * 从文件 order.txt 读取所有预约记录到数组
 * @param orders 存储记录的结构体数组
 * @param count 指针，返回实际读取的记录数
 * @return 成功返回1，失败返回0
 */
int read_data(bus_order *orders, int *count) {
    FILE *fp = fopen("order.txt", "r");
    if (fp == NULL) {
        /* 文件不存在时无记录，不算错误 */
        *count = 0;
        return 1;
    }

    int i = 0;
    while (i < MAX_RECORDS &&
           fscanf(fp, "%s %s %d %d %d %d",
                  orders[i].No,
                  orders[i].name,
                  &orders[i].trav_line_no,
                  &orders[i].order_date.year,
                  &orders[i].order_date.month,
                  &orders[i].order_date.day) == 6) {
        i++;
    }
    fclose(fp);
    *count = i;
    return 1;
}

/**
 * 获取当前系统日期，填充到指针参数 d 中
 */
void get_current_date(Date *d) {
    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now = localtime(&now);
    d->year  = tm_now->tm_year + 1900;
    d->month = tm_now->tm_mon + 1;
    d->day   = tm_now->tm_mday;
}

/**
 * 判断日期 d1 是否不早于 d2（d1 >= d2）
 * @return 1表示 d1 >= d2，0表示 d1 < d2
 */
int date_not_earlier(Date d1, Date d2) {
    if (d1.year > d2.year) return 1;
    if (d1.year < d2.year) return 0;
    if (d1.month > d2.month) return 1;
    if (d1.month < d2.month) return 0;
    return d1.day >= d2.day;
}

/**
 * 预约班车模块
 * 输入学号、姓名、线路号、日期，校验后追加到 order.txt
 */
void order(void) {
    bus_order new_order;
    Date today;
    get_current_date(&today);

    printf("\n请输入学号/工号 (8位): ");
    scanf("%8s", new_order.No);
    printf("请输入姓名: ");
    scanf("%s", new_order.name);
    printf("请输入班车线路编号 (1~10): ");
    scanf("%d", &new_order.trav_line_no);
    if (new_order.trav_line_no < 1 || new_order.trav_line_no > 10) {
        printf("线路编号无效，预约失败！\n");
        return;
    }

    printf("请输入预约日期 (年 月 日，用空格分隔): ");
    scanf("%d %d %d", &new_order.order_date.year,
          &new_order.order_date.month,
          &new_order.order_date.day);

    /* 校验日期是否不早于今天 */
    if (!date_not_earlier(new_order.order_date, today)) {
        printf("预约日期不能早于当前日期(%d-%d-%d)，预约失败！\n",
               today.year, today.month, today.day);
        return;
    }

    /* 追加写入 order.txt */
    FILE *fp = fopen("order.txt", "a");
    if (fp == NULL) {
        printf("无法打开数据文件，预约失败！\n");
        return;
    }
    fprintf(fp, "%s %s %d %d %d %d\n",
            new_order.No,
            new_order.name,
            new_order.trav_line_no,
            new_order.order_date.year,
            new_order.order_date.month,
            new_order.order_date.day);
    fclose(fp);

    printf("预约成功！\n");
}

/**
 * 查询预约信息模块
 * 读取文件全部记录，根据学号匹配并输出
 */
void query(void) {
    bus_order orders[MAX_RECORDS];
    int count, i, found = 0;
    char key[9];

    if (!read_data(orders, &count)) {
        printf("读取数据出错！\n");
        return;
    }
    if (count == 0) {
        printf("暂无任何预约记录。\n");
        return;
    }

    printf("\n请输入要查询的学号/工号: ");
    scanf("%8s", key);

    printf("\n========== 查询结果 ==========\n");
    for (i = 0; i < count; i++) {
        if (strcmp(orders[i].No, key) == 0) {
            printf("姓名: %s\n", orders[i].name);
            printf("班车线路: %d\n", orders[i].trav_line_no);
            printf("预约日期: %d-%d-%d\n",
                   orders[i].order_date.year,
                   orders[i].order_date.month,
                   orders[i].order_date.day);
            printf("------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("未找到该用户的预约记录。\n");
    }
    printf("==============================\n");
}