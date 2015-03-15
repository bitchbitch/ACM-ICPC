// Fie Name: c.c
// Author: darkdream
// Created Time: 2013年08月17日 星期六 00时47分02秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#define MOD 1000000009
long long  Pow(long long k )
{
   
   if(k == 1 )
	   return 2; 
   else
   {
	   long long t = Pow(k/2) % MOD;
	   if(k % 2 == 0 )
	   return ( t*t ) % MOD;
      else return (t * t) % MOD* 2 % MOD;
   }
}

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   long long n, m , k ; 
   scanf("%I64d %I64d %I64d",&n,&m,&k);
   int t = (m-(n-m)*(k-1))/k;
   if(t < 0)
	  printf("%I64d",m);
   else { 
	long long ans = ((Pow(t+1)-2)*k  + m - t*k ) % MOD;
	if(ans < 0 )
		ans = MOD +ans;
	 printf("%I64d\n",ans);
   }
return 0 ;
}
