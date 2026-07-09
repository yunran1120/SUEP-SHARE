/* c12-2-2.c */
#include <stdio.h>
int main()
{
	char s[20];
	char *p;
	printf("please input string:\n");
	scanf("%s",s);
	p=s;
	while(*p!='\0')
	{
		if(*p>='A'&&*p<='Z') *p=*p-'A'+'a';
		p++;
	}
	p=s;
	while(*p!='\0')
	{
		putchar(*p);
		p++;
	}
	printf("\n");
	return 0;
}