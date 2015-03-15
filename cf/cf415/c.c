// File Name: c.c
// Author: darkdream
// Created Time: 2014年04月07日 星期一 00时13分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n , m ; 
   scanf("%d %d",&n,&m);
   if(m < n/2)
   {
	  printf("-1");
      return 0; 
   }
   if(n == 1 )
   {
     if(m == 0)
		 printf("1\n");
	 else printf("-1\n");
	 return 0;
   }
   int i ; 
   int ans = m - (n/2 -1);
   printf("%d %d ",ans,ans*2);
   for(i = 1;i <= (n/2-1)*2;i ++)
	   printf("%d ",ans *2 + i );

   if(n % 2 == 1 )
   {
	   if(ans == 1) 
		   printf("%d\n",ans*2+i);
	   else printf("1\n");
   
   }
return 0 ;
}
