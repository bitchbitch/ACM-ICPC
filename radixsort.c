// File Name: radixsort.c
// Author: darkdream
// Created Time: 2014年03月02日 星期日 16时59分36秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[100000];
int b[100000];
void radixsort(int *a, int n)
{
	int i, m = a[0], exp = 1;
	for (i = 1; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}

	while (m / exp > 0)
	{
		int bucket[10] ={ 0 };
		for (i = 0; i < n; i++)
			bucket[(a[i] / exp) % 10]++;
		for (i = 8; i >= 0; i --)
			bucket[i] += bucket[i +1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[(a[i] / exp) % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
int main(){
	int n ; 
   scanf("%d",&n);
    for(int i = 0 ;i < n;i ++)
		scanf("%d",&a[i]);
	radixsort(a,n);
	for(int i = 0;i < n;i ++)
	    printf("%d ",a[i]);
	return 0 ;
}
