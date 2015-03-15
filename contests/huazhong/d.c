// File Name: d.c
// Author: darkdream
// Created Time: 2014年03月30日 星期日 12时28分38秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
#define M 1000000007
long long a[100];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   a[1] = 1; 
   a[2] = 1; 
  for(int i = 3;i <= 99;i ++)
  {
    a[i] = (a[i-1] + a[i-2]) %M;
  }
  long long sum = 0 ; 
  for(int i = 1;i <= 99;i++)
  {
	  sum = (sum +(a[i]*a[i])%M*a[i] %M) %M;
	  printf("%lld %lld\n",sum,a[i]);
 
  }
return 0 ;
}
