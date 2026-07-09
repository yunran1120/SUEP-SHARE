/*  c5-2-11.c  */ 
#include <stdio.h>
int main()
{
	double money_poor=100000.0, money_rich=0.01;
	double total_poor=0.0, total_rich=0.0;
	int day=1;
	do{
		total_poor+=money_rich;
		total_rich+=money_poor;
		money_rich*=2;
		day++;
	}while(day<=30);
	printf("富翁给了陌生人:%.2f元，陌生人给了富豪：%.2f元。",total_poor, total_rich);
	return 0;
}