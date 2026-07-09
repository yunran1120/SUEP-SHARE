/* c6-2-2.c  */
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, flag, sum = 0;
	for (i = 100; i <= 200; i++)
    {
        /**********found**********/
        flag = 0;
        for (j = 2; j <= i - 1; j++)
        {
            /**********found**********/
            if (i%j==0)
            {
                flag = 1;
                break;
            }
        }
        /**********found**********/
        if (flag==0)
            sum += i;
    }
    printf("The sum is %d\n", sum);
    return 0;
}