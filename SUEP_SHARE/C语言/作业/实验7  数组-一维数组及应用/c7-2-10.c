/*  c7-2-10.c  */
#include<stdio.h>
#include<math.h>
#define N 100
int main()
{   int n,k,i,prim[N],count=0;
       for(n=1;n<=100;n++)
       {   k=sqrt(n);
           for(i=2;i<=k;i++)
                 if(n%i==0) break;
            if(i==k+1) 
			{
				prim[count]=n;
        		count++;
			}
			
        }
    for(i=0;i<count;i++) 
       	printf("%5d",prim[i]);
	return 0;
}
