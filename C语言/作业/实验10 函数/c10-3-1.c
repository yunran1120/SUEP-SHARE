/* c10-3-1.c */
#include <stdio.h>

int txt_read(char *filename,int id[],int math[],int eng[],int c[]);
void cal_avg(int math[],int eng[],int c[],double avg[],int count);
void sort(int id[],int math[],int eng[],int c[],double avg[],int count);
void print_result(char *filename,int id[], int math[], int english[], int c_lang[],double average[], int count);

int main()
{
	int id[4];
    int math[4];
    int eng[4];
    int c[4];
    double avg[4];
    int count;
    count=txt_read("score.txt",id,math,eng,c);
    if (count == 0) {
        printf("没有读到任何学生记录，程序退出。\n");
        return 1;
    }
    cal_avg(math, eng, c, avg, count);
    sort(id,math, eng, c, avg, count);
    print_result("score_avg.txt",id,math, eng, c, avg, count);
    return 0;
}

int txt_read(char *filename,int id[],int math[],int eng[],int c[])
{
	FILE *fp;
	fp=fopen(filename, "r");
    if (fp == NULL) {
        printf("打开文件失败");
        return 0;
    }
    int count=0;
    while(fscanf(fp, "%d %d %d %d",&id[count], &math[count],&eng[count], &c[count]) == 4)
	{
		count++;
	}
	fclose(fp);
	return count;
    
}

void cal_avg(int math[],int eng[],int c[],double avg[],int count)
{
	for(int i=0;i<count;i++)
	{
		avg[i]=(math[i]+eng[i]+c[i])/3;
	}
}

void sort(int id[],int math[],int eng[],int c[],double avg[],int count)
{
	int i,j,temp;
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-1-i;j++)
		{
			if (avg[j]<avg[j+1])
			{
				temp=avg[j];
				avg[j]=avg[j+1];
				avg[j+1]=temp;
				
				temp=id[j];
				id[j]=id[j+1];
				id[j+1]=temp;
				
				temp=math[j];
				math[j]=math[j+1];
				math[j+1]=temp;
				
				temp=eng[j];
				eng[j]=eng[j+1];
				eng[j+1]=temp;
				
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
			}
		}
	}
}

void print_result(char *filename,int id[], int math[], int english[], int c_lang[],double average[], int count)
{
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
        printf("无法创建输出文件");
        return;
    }
    printf("%-6s %-6s %-6s %-6s %-8s\n", "学号", "高数", "英语", "C语言", "平均分");
    fprintf(fp, "%-6s %-6s %-6s %-6s %-8s\n", "学号", "高数", "英语", "C语言", "平均分");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-6d %-6d %-6d %-8.2f\n",
               id[i], math[i], english[i], c_lang[i], average[i]);
        fprintf(fp, "%-6d %-6d %-6d %-6d %-8.2f\n",
                id[i], math[i], english[i], c_lang[i], average[i]);
    }
    fclose(fp);
    printf("\n结果已保存至 %s\n", filename);
}