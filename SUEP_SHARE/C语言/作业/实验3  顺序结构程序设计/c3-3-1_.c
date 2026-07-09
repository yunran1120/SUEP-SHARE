/*  c3-3-1.c  */
#include <stdio.h>
int main()
{
    int id;
    float M,E,C,A;
    FILE*fp;
    printf("请输入学号:");
    scanf("%d",&id);
    printf("请输入高数成绩:");
    scanf("%f",&M);
    printf("请输入英语成绩:");
    scanf("%f",&E);
    printf("请输入C语言成绩:");
    scanf("%f",&C);
    A=(M+E+C)/3;
    fp=fopen("score_avg.txt","w");
    fprintf(fp,"学号     高数    英语    C语言    平均分\n");
    fprintf(fp,"%d    %d      %d       %d         %.2f\n",id,(int)M,(int)E,(int)C,A);
    fclose(fp);
    return 0;
}
