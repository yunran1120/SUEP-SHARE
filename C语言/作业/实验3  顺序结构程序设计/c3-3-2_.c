/*  c3-3-2.c  */
#include <stdio.h>
int main()
{
	int id,M,E,C;
    FILE*fp_in,*fp_out;
    fp_in=fopen("score.txt","r");
    fscanf(fp_in,"%d %d %d %d",id,M,E,C);
    fclose(fp_in); 
    printf("%d,%d,%d,%d",&id,&M,&E,&C);
    fp_out=fopen("score_avg.txt","w");
    fprintf(fp_out,"%d  %d  %d  %d",id,M,E,C);
    fclose(fp_out);
    return 0;
}
