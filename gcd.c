// File Name: gcd.c
// Author: darkdream
// Created Time: 2014年03月11日 星期二 20时23分17秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int gcd(int a, int b)
{
  return b == 0 ? a: gcd(b,b%a);
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   for(int i = 1;i <= 359;i++)
   {
     printf("%d\n",360*i/gcd(i,360));
   }
return 0 ;
}
