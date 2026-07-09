/*  c5-2-9.c  */ 
#include <stdio.h> 
int main( ) 
{  
	int i; 
	long long p,sum; 
	p=1;sum=0; 
	for(i=1; i<=20; i++ ) 
	{  
		p=p*i; 
		sum=sum+p; 
	} 
	printf("Sum=%lld",sum) ; 
}