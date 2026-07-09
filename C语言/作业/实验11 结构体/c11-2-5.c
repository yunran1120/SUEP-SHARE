/*  c11-2-5.c  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 200

typedef struct {
    int num;
    char name[30];
    int math;
    int english;
    int c_lang;
    float average;
} Student;

int read_from_file(const char *filename, Student *stu);
void calculate_average(Student *stu, int n);
void sort_by_average(Student *stu, int n);
void output(const char *filename, Student *stu, int n);

int main() {
    Student stu[MAX_STUDENTS];
    int n;

    n = read_from_file("score.txt", stu);
    if (n == 0) {
        printf("文件中无数据或打开失败！\n");
        return 1;
    }

    calculate_average(stu, n);

    sort_by_average(stu, n);

    output("score_avg.txt", stu, n);

    printf("\n处理完成！结果已保存到 score_avg.txt\n");
    return 0;
}

int read_from_file(const char *filename, Student *stu) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("文件打开失败");
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%d %s %d %d %d",
                  &stu[count].num,
                  stu[count].name,
                  &stu[count].math,
                  &stu[count].english,
                  &stu[count].c_lang) == 5) {
        count++;
        if (count >= MAX_STUDENTS) {
            printf("警告：已达到最大学生人数上限 %d\n", MAX_STUDENTS);
            break;
        }
    }
    fclose(fp);
    return count;
}

void calculate_average(Student *stu, int n) {
    for (int i = 0; i < n; i++) {
        stu[i].average = (stu[i].math + stu[i].english + stu[i].c_lang) / 3.0f;
    }
}

void sort_by_average(Student *stu, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (stu[j].average < stu[j + 1].average) {
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

void output(const char *filename, Student *stu, int n) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("无法创建输出文件");
        return;
    }
    printf("%-8s %-10s %6s %6s %6s %8s\n", "学号", "姓名", "高数", "英语", "C语言", "平均分");
    fprintf(fp, "%-8s %-10s %6s %6s %6s %8s\n", "学号", "姓名", "高数", "英语", "C语言", "平均分");

    for (int i = 0; i < n; i++) {
        printf("%-8d %-10s %6d %6d %6d %8.2f\n",
               stu[i].num, stu[i].name,
               stu[i].math, stu[i].english, stu[i].c_lang,
               stu[i].average);
        fprintf(fp, "%-8d %-10s %6d %6d %6d %8.2f\n",
                stu[i].num, stu[i].name,
                stu[i].math, stu[i].english, stu[i].c_lang,
                stu[i].average);
    }
    fclose(fp);
}