// File Name: b.c
// Author: darkdream
// Created Time: 2014年02月26日 星期三 23时47分13秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  __int64 t ; 
  scanf("%I64d\n",&t);
  for(__int64 i = 1;i <= t;i ++)
  {
	__int64 n , l , r ;
    scanf("%I64d %I64d %I64d",&n,&l,&r);
	__int64 k = n/l;
	__int64 t = n %l;
//	printf("%I64d %I64d\n",k,t);
    if(k * (r-l)  >=  t)
		printf("Yes\n");
	else printf("No\n");
  }
return 0 ;
}
