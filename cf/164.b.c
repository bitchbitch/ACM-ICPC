// File Name: 164.b.c
// Author: darkdream
// Created Time: 2013年01月28日 星期一 23时41分57秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  int n , i ,j, sum = 0;
  scanf("%d",&n);
  int a[3000];
  for (i = 1; i <= n; i++)
  {
      a[i] = n -i+1 ;

  }
  

   for (i = 1; i<= n; i++)
   {  
     sum += i * (a[i]-1);
   }
   sum = sum+n;
   printf("%d",sum);
return 0 ;
}
