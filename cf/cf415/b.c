// File Name: b.c
// Author: darkdream
// Created Time: 2014年04月06日 星期日 23时49分44秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
long long n , a, b ; 
long long gcd(long long a ,long long b)
{
  return b ==0 ? a:gcd(b,a%b);
 }
int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   scanf("%lld %lld %lld",&n,&a,&b);
   for(int i = 1;i <= n;i ++)
   {
       long long  temp,c,d; 
	   scanf("%lld",&temp);
	   long long ans = (temp * a) %b;
       ans = ans/a;
	   printf("%lld ",ans);
   }
return 0 ;
}
