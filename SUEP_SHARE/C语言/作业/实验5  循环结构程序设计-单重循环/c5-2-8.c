/*  c5-2-8.c  */ 
#include <stdio.h> 
int  main( ) 
{  
	char ch;
	int zimu,kongge,shuzi,qita;
	zimu=0;kongge=0;shuzi=0;qita=0;
	printf("请输入一行字符（以回车结束）：\n");
	ch=getchar();     
	while(ch!='\n') 
	{  
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))  zimu++; //   
		else if(ch == ' ') kongge++; 
		else if(ch >= '0' && ch <= '9') shuzi++;
		else qita++;
		ch=getchar();  
	}
	printf("英文字母个数：%d\n", zimu);
	printf("空格个数：%d\n", kongge);
	printf("数字个数：%d\n", shuzi);
	printf("其他字符个数：%d\n", qita);
	return 0; 
}