// File Name: hdu2204.c
// Author: darkdream
// Created Time: 2013年06月14日 星期五 20时14分54秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  long long int n ; 
  while(scanf("%lld",&n) != EOF)
  {
	   int sum = 0 ;
       for(int i = 2;i <= 32;i ++)
	   {
		   sum += pow(n,1.0/i) - pow(n,1.0/(i*2));
	   }
	   printf("%d\n",sum);
  }

return 0 ;
}
