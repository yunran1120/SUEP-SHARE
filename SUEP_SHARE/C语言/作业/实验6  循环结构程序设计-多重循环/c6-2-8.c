/* c6-2-8.c */
#include <stdio.h>
int main()
{
    double fenzi = 2.0;   
    double fenmu = 1.0; 
    double sum = 0.0;         
    int i;
    for (i = 1; i <= 20; i++)
    {
        sum += fenzi / fenmu;
        double next_fenzi = fenzi + fenmu;
        fenmu = fenzi;
        fenzi = next_fenzi;
    }
    printf("前20项之和为：%f\n", sum);
    return 0;
}