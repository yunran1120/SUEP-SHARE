#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define M 5
int   id[MAXN];
double avg[MAXN];
void swapAll(int i, int j)
{
    double t1 = avg[i]; avg[i] = avg[j]; avg[j] = t1;
    int    t2 = id[i];  id[i] = id[j];   id[j] = t2;
}
void sort(int n)
{
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j)
            if (avg[j] > avg[k]) k = j;
        if (k != i) swapAll(i, k);
    }
}
int main()
{
    FILE *fin = fopen("score.txt", "r");
    if (!fin) { printf("打开 score.txt 失败"); return 0; }
    int n = 0;
    double score[M];
    while (fscanf(fin, "%d", &id[n]) == 1)
	{
        for (int i = 0; i < M; ++i)  fscanf(fin, "%lf", &score[i]);
        double sum = 0, max = score[0], min = score[0];
        for (int i = 0; i < M; ++i)
		{
            sum += score[i];
            if (score[i] > max) max = score[i];
            if (score[i] < min) min = score[i];
        }
        avg[n] = (sum - max - min) / (M - 2);
        ++n;
    }
    fclose(fin);
    sort(n);
    FILE *fout = fopen("score.txt", "a");
    if (!fout) { printf("追加写入失败"); return 0; }
    fprintf(fout, "\n=== 最终名次 ===\n");
    for (int i = 0; i < n; ++i)
        fprintf(fout, "%-3d %03d  %.2f\n", i + 1, id[i], avg[i]);
    fclose(fout);
    printf("=== 最终名次 ===\n");
    for (int i = 0; i < n; ++i)
        printf("%-3d %03d  %.2f\n", i + 1, id[i], avg[i]);
    return 0;
}