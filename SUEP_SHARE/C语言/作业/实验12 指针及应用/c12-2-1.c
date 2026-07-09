/* c12-2-1.c */
# include <stdio.h>
int main()
{
	char s[20];
	int i;
	printf("please input string:\n");
	gets(s);
	for(i=0;i<20;i++)
		if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+'a'-'A';
	puts(s);
	return 0;
}
