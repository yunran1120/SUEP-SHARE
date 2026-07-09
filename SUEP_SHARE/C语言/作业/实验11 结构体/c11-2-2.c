/*  c11-2-2.c  */ 
#include <stdio.h>
#define N 5
struct man
{
	char name[20];
	int age;
};//少了个分号
int main()
{
	struct man person[]={{"Li",20},{"Yang",21},{"Sun",18},{"zhao",23},{"lin",17}}; //struct后面加上man
	int i,kmin;
	kmin=0;
	for(i=1;i<N;i++)
	{
		if(person[i].age<person[kmin].age) kmin=i;
	}
	printf("年龄最小者为：%s ,其年龄为  %d\n",person[kmin].name,person[kmin].age);//i换成kmin
	return 0;
}