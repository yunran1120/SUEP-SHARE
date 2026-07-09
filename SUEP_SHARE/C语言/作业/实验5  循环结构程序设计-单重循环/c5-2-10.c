/*  c5-2-10.c  */ 
#include <stdio.h>
#include <math.h>
int main()
{
    double product = 1.0;
    double item;
    int k = 1;
    do {
        item = 1.0 / ((2*k - 1) * (2*k + 1));
        product *= (1 + item);
        k++;
    } while (item >= 1e-6);
    double pi = 2 * product;
	printf("π ≈ %.10f\n", pi);
    return 0;
}