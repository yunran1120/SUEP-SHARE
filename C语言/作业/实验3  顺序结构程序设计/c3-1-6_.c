/*   c3-1-6.c    */
#include <stdio.h> 
int main() 
{   
	int a,b; 
	unsigned c,d; 
	a = 4294967295; 
	b = -4294967295; 
	c = a; 
	d = b;               
	printf("a=%d, b=%d\n", a, b); 
	printf("a=%u, b=%u\n", a, b);   
	printf("c=%u, d=%u\n", c, d); 
	return 0; 
}