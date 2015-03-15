// File Name: c.c
// Author: darkdream
// Created Time: 2014年04月27日 星期日 13时00分17秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(){
	int n; 
    while(scanf("%d",&n) != EOF)
	{
	   long long sum ,tsum ; 
	   sum = tsum =0 ; 
	   int k = floor(sqrt(n)+1e-8) + 1e-8; 
	   for(int i = 1;i <= k;i ++)
		{
		   if(n % i == 0 )
			   tsum += i + n/i ;
		}
	   if(k*k == n)
		   tsum -= k;
		//printf("%lld\n",tsum);
		printf("%lld\n",tsum - (n*(n+1)/2 - tsum) - 1);
	}
return 0 ;
}
