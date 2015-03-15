// File Name: 2145.c
// Author: darkdream
// Created Time: 2013年08月17日 星期六 23时24分46秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char str[10000000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   gets(str);
   int len = strlen(str);
   if((str[len-1] - '0') %2 == 0 )
	   printf("ou\n");
   else printf("ji\n");
return 0 ;
}
