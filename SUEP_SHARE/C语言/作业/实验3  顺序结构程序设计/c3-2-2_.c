/*  c3-2-2.c  */
#include <stdio.h> 
int main() 
{
    int a,b,t; 
    printf("请输入变量a、b的值:");
    scanf("%d %d",&a,&b);
    printf("交换前:a=%d,b=%d\n",a,b);
    t=a;
    a=b;
    b=t;
    printf("交换后:a=%d,b=%d",a,b);
    return 0;
}
