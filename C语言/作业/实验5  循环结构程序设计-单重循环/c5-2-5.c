/*c5-2-5.c*/ 
#include <stdio.h> 
int main() 
{    
	int s, t, sl=10; 
	printf("\nPlease enter s:");  
	scanf("%d", &s); 
	t = s%10; 
	while ( s > 0) 
	{   
		s = s/100; 
		t = s%10 * sl + t; 
		/************found************/ 
		sl = sl*10; 
	} 
	printf("The result is: %d\n", t); 
	return 0; 
} 