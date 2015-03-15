// File Name: d.c
// Author: darkdream
// Created Time: 2013年02月25日 星期一 00时17分42秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  __int64  a , b;
  int c[70] = {0},d[70] = {0};
  scanf("%I64d %I64d",&a,&b);
  for(int i = 1;i <= 66  ;i++)
  {
    c[i] = a%2;
	d[i] = b%2;
	a = a/2;
	b = b/2;
  }
  int i ;
  for(i = 69 ;i >= 0 ;i --)
	  if(c[i] != d[i])
		 break; 
   if(i == 0)
	   printf("0");
   else
   { __int64  sum = 1;
   for(int j = 1 ;j <= i; j++)
	   sum = sum*2;
   sum = sum -1;
   printf("%I64d",sum);
   }
  
return 0 ;
}
