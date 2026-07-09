/*  c5-3-1.c  */ 
#include <stdio.h>
int main()
{
	int x,g,y,c;
	float avg;
	FILE*fp_r,*fp_w;
	fp_r=fopen("score.txt","r");
	fp_w=fopen("score_avg.txt","w");
	if (fp_r == NULL || fp_w == NULL) 
	{
    	printf("文件打开失败！\n");
    	return 1;
	}
	fprintf(fp_w, "学号\t高数\t英语\tC语言\t平均分\n");
    fscanf(fp_r,"%d%d%d%d",&x,&g,&y,&c);
	do{
		avg=(g+y+c)/3.0;
		fprintf(fp_w,"%d\t%d\t%d\t%d\t%.2f\n",x,g,y,c,avg);
		printf("学号%d的同学的成绩为：高数%d分，英语%d分，C语言%d分，平均分%.2f分\n",x,g,y,c,avg);
	}while(fscanf(fp_r, "%d%d%d%d", &x, &g, &y, &c) == 4);
	return 0;
}