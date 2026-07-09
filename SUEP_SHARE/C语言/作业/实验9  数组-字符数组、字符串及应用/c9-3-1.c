/* c9-3-1.c */
#include <stdio.h>
#include <string.h>
#define MAX 200
int main()
{
    int id[MAX];
    char name[MAX][20];
    int math[MAX], eng[MAX], c[MAX];
    double avg[MAX];
    int n = 0;
    FILE *fp_in, *fp_out;
    fp_in = fopen("score.txt", "r");
    if (fp_in == NULL)
    {
        printf("无法打开 score.txt 文件\n");
        return 1;
    }
    while (fscanf(fp_in, "%d %s %d %d %d",&id[n], name[n], &math[n], &eng[n], &c[n]) == 5)
    {
        avg[n] = (math[n] + eng[n] + c[n]) / 3.0;
        n++;
        if (n >= MAX) break;
    }
    fclose(fp_in);
    int i, j, max_idx;
    for (i = 0; i < n - 1; i++)
    {
        max_idx = i;
        for (j = i + 1; j < n; j++)
            if (avg[j] > avg[max_idx])
                max_idx = j;
        if (max_idx != i)
        {
            int tmp_int;
            double tmp_dbl;
            char tmp_name[20];

            tmp_int = id[i];      id[i] = id[max_idx];      id[max_idx] = tmp_int;
            tmp_int = math[i];    math[i] = math[max_idx];  math[max_idx] = tmp_int;
            tmp_int = eng[i];     eng[i]  = eng[max_idx];   eng[max_idx]  = tmp_int;
            tmp_int = c[i];       c[i]    = c[max_idx];     c[max_idx]    = tmp_int;
            tmp_dbl = avg[i];     avg[i]  = avg[max_idx];   avg[max_idx]  = tmp_dbl;

            strcpy(tmp_name, name[i]);
            strcpy(name[i], name[max_idx]);
            strcpy(name[max_idx], tmp_name);
        }
    }
    printf("学号 姓名 高数 英语 C语言 平均分\n");
    for (i = 0; i < n; i++)
        printf("%d %s %d %d %d %.2f\n",
               id[i], name[i], math[i], eng[i], c[i], avg[i]);
    fp_out = fopen("score_avg.txt", "w");
    if (fp_out == NULL)
    {
        printf("无法创建 score_avg.txt 文件\n");
        return 1;
    }
    fprintf(fp_out, "学号 姓名 高数 英语 C语言 平均分\n");
    for (i = 0; i < n; i++)
        fprintf(fp_out, "%d %s %d %d %d %.2f\n",
                id[i], name[i], math[i], eng[i], c[i], avg[i]);
    fclose(fp_out);

    return 0;
}