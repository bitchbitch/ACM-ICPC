// File Name: uva10110.c
// Author: darkdream
// Created Time: 2013年03月02日 星期六 16时34分29秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   long long int n ;
  while(scanf("%lld",&n),n)
  {

     double k = floor(sqrt(n));
	 if(k*k == n)
		 printf("yes\n");
	 else
		 printf("no\n");
  }
return 0 ;
}
