// File Name: uva10790.c
// Author: darkdream
// Created Time: 2013年02月18日 星期一 20时38分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   long long  int a, b ,t = 1;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
	   if (a== 0 && b== 0 )
	       break;
        long long sum = 0 ;
		  sum = a*(a-1)/2*(b-1)*b/2;
     printf("Case %lld: %lld\n",t,sum);
	 t++;
	}

return 0 ;
}
