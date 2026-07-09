/*  c2-3-1.c  */ 
#include <stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("test.txt","w");
	printf("我爱你，中国！");
	fprintf(fp,"我爱你，中国！");
	fclose(fp);
	return 0;
}