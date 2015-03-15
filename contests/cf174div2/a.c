// File Name: a.c
// Author: darkdream
// Created Time: 2013年03月17日 星期日 23时30分18秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int p , sum  =0;
   scanf("%d",&p);
   for(int i = 2 ;i <= (p+1)/2 ; i ++ )
   {
      if((p+1) % i == 0)
		  sum++;
   }
  printf("%d",sum);

return 0 ;
}
