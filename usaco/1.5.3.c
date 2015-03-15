// File Name: 1.5.3.c
// Author: darkdream
// Created Time: 2013年01月23日 星期三 19时06分04秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int is_prime(long long int a )
{
    int i ;
	int j = sqrt(a*1.0);
	for (i = 2; i <= j ; i++)
		if (a % i == 0)
			return  0 ;
	return 1;
}

int main(){
    long long int a[10000];
    int i , j , k ;
	a[0] = 2; 
	a[1] = 3; 
	a[2] = 5; 
    a[3] = 7;
    k = 3; 
	for (i = 0; i <= k ;i ++)
      for (j = 1; j <= 9 ; j++ )
	  {  if (is_prime(a[i]*10+j))
			  a[++k] = a[i]*10 +j;
	     if(a[k] >= 1000000000)
			 break;
	  }
	int n;
	scanf("%d",&n);
	for (i = 0; i<= k ;i++)
      if (a[i] >= pow(10.0,n-1) && a[i] <= pow(10.0,n))
		  printf("%lld\n",a[i]);

return 0 ;
}
