// File Name: k.c
// Author: darkdream
// Created Time: 2014年04月04日 星期五 20时31分44秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t;
   scanf("%d\n",&t);
   for(int i =1;i<= t;i ++)
   {
      long long n ,m; 
	  scanf("%lld %lld",&n,&m);
	  
	  printf("Case %d: %lld\n",i,n/2*m);
   }
return 0 ;
}
