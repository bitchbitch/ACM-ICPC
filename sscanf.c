// File Name: sscanf.c
// Author: darkdream
// Created Time: 2014年03月11日 星期二 20时54分20秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  char a[100];
  gets(a);
  int temp ; 
  char p ;
  sscanf(a,"%d",&temp);

  printf("%d\n",sscanf(a,"%d",&temp));
return 0 ;
}
