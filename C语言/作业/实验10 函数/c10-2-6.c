/* c10-2-6.c */
#include <stdio.h>
int sum(int arr[],int n)
{
	int i,s;
	s=0;
	for(i=0;i<n;i++)
		if(arr[i]%2==0) s=s+arr[i];
	return (s);
}

int main()
{
	int a[10]={10,4,2,7,3,12,5,34,5,9},s;
	s=sum(a,10);
	printf("The result is: %d\n", s);
	return 0;
}