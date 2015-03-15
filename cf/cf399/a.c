// File Name: a.c
// Author: darkdream
// Created Time: 2014年03月01日 星期六 23时25分19秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int n , p , k ; 
   scanf("%d %d %d",&n,&p,&k);
   int ta,tb;
   ta = p - k -1;
   tb = p + k + 1;
   if(ta < 1 )
	 {
	   ta = 1;
	   if(p != 1)
	   printf("1 ");
	 }
   else printf("<< ");
   for(int i = ta +1 ;i < p ;i ++)
	   printf("%d ",i);
   printf("(%d) ",p);
   if(tb > n)
   {
      tb = n +1 ;
   }
   for(int i = p + 1;i < tb ;i ++)
   {
        printf("%d ",i);
   }
   if(tb != n+1)
   printf(">>");
return 0 ;
}
