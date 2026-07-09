/*  c2-2-1.c  */
#include <stdio.h>
int main()
{
	int j;
	char ch;
	printf("Input ch:");
	ch=getchar();
	j=ch+32;
	putchar(ch);
	printf("\nch：%d",ch);
	return 0;
}