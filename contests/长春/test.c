// File Name: test.c
// Author: darkdream
// Created Time: 2013年09月28日 星期六 13时27分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);

int main(){
   int n = 54653;//2022161;
   for(int i = n ;i >= 1;i --)
	   if(n % i == 0 )
		   printf("%d\n",i);

return 0 ;
}
