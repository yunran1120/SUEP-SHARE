/*  c2-3-2.c  */ 
#include <stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("春晓.txt","w");
	printf("春眠不觉晓\n处处闻啼鸟\n夜来风雨声\n花落知多少");
	fprintf(fp,"春眠不觉晓\n处处闻啼鸟\n夜来风雨声\n花落知多少");
	fclose(fp);
	return 0;
}