/*  c3-2-4.c  */
#include <stdio.h> 
int main() 
{
    float F,C;
    printf("请输入华氏温度:");
    scanf("%f",&F);
    C=((F-32)*5/9);
    printf("摄氏温度为:%.2f\n",C);
    return 0;
}
