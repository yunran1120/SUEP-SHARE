/*  c3-2-6.c  */
#include <stdio.h>
#define PI 3.1415926
int main()
{
    float r,h,c,s,v;
    printf("请输入圆的半径和圆柱的高:");
    scanf("%f %f",&r,&h);
    c= 2*PI*r;
    s=PI*r*r;
    v=s*h;
    printf("圆的周长为:%.2f\n",c);
    printf("圆的面积为:%.2f\n",s);
    printf("圆柱的体积为:%.2f\n",v);
    return 0;
}
