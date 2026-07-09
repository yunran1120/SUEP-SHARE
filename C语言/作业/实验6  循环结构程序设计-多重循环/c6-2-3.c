/* c6-2-3.c  */
#include <stdio.h>
#include <math.h>
int main()
{
    float i, j, k;
    printf("\t五角\t二角\t一角\n");
    /**********found**********/
    for (i = 0; i <= 2; i++)
        for (j = 0; j <= 5; j++)
            for (k = 0; k <= 10; k++)
            {
                /**********found**********/
                if (i * 5 + j * 2 + k * 1 == 10)
                    printf("\t%.0f\t%.0f\t%.0f\n", i, j, k);
            }
    return 0;
}