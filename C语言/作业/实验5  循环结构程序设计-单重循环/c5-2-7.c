/*  c5-2-7.c  */ 
#include <stdio.h> 
int  main( ) 
{
	int m,n,t,s,i; 
	m=0;n=0;s=0;
	scanf("%d%d",&m,&n); 
	if( m>n ) {
		t=m;
		m=n;
		m=t; 
	}
	
	for (i=m;i<=n;i=i+1)
	{   
		if ( i%3!=0 && i%7!=0 ) //该数不能被3整除也不能被7整除
			s=s+i ; 
	} 
	printf("Sum is : %d \n",s ); 
	return 0; 
}