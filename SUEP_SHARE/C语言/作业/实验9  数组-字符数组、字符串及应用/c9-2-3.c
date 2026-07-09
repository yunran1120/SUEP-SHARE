/* c9-2-3.c */
#include <stdio.h>
int main()
{
	char str[80]="This Is a c Program";
	int i;
	printf("String is: %s\n", str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='A' && str[i]<='Z')
			str[i]=str[i]+32;
	}
	printf("Result is: %s\n",str);
	return 0;
}