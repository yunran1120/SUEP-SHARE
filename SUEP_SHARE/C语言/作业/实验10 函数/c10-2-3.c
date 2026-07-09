/* c10-2-3.c */
#include <stdio.h>
int fun(int arr[],int n);
int main()
{
	int a[12]={1,8,5,10,6,18,7,2,4,12,9,11};
	printf("The result is : %ld\n",(long)fun(a,12));
	return 0;
}
int fun(int arr[],int n)
{
	int i;
	int s=0;
	for(i=0;i<n;i++)
		if(arr[i]%3!=0 && arr[i]%5!=0)
			s+=arr[i];
	return (s);
}