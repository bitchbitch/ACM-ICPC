// File Name: first.c
// Author: darkdream
// Created Time: 2014年03月07日 星期五 19时57分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define M 1000000007
long long  f[2000];
long long P(int n)
{
   if(n == 0 )
	   return 1;
   if(n == 1 )
	   return 2; 
   long long temp = P(n/2) % M ; 
   if(n % 2 == 0 )
	   return temp * temp % M ;
   return temp *temp * 2 % M;
}
int main(){
    f[1] = 2; 
	f[2] = 12; 
	for(int i = 3;i <= 1000 ;i ++)
		f[i] = 2*(f[i-1] + 2 * f[i-2]+  P(i-1)) % M;
	int n ; 
	scanf("%d",&n);
    if(n == 1 )
    {
     printf("2\n");
	 return 0 ; 
    }
    long long sum = 0 ; 
	sum = f[n]*2 %M;
    for(int i = 2;i <= n-1 ; i ++)
	{
	    sum += 2*(P(n-i)*f[i-1] + P(i-1)*f[n-i]) % M  ;
		sum = sum % M ; 
	}
	printf("%lld\n",sum);
return 0 ;
}
