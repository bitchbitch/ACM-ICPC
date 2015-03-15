// File Name: a.c
// Author: darkdream
// Created Time: 2013年06月15日 星期六 12时04分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   long long  n , m;
   scanf("%lld %lld",&n,&m);
   long long  t = ceil(n/2.0);
   if(m <= t)
   {
     printf("%lld\n",2*m-1);
   }
   else
   {
     printf("%lld\n",2*(m-t));
   }
return 0 ;
}
