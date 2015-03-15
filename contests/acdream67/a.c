// File Name: a.c
// Author: darkdream
// Created Time: 2014年04月04日 星期五 20时18分20秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t ; 
   scanf("%d",&t);
   for(int j = 1;j <= t;j ++)
   {
     int a, b, c, d ; 
	 scanf("%d %d %d %d",&a,&b,&c,&d);
	 int q; 
	 scanf("%d",&q);
	 printf("Case %d:\n",j);
	 for(int i =1;i <= q;i ++)
	 {
	
	   int tx, ty ; 
	   scanf("%d %d",&tx,&ty);
	   if(tx >= a && tx <= c &&  ty >= b && ty <= d)
		   printf("Yes\n");
	   else printf("No\n");
	 }
   }
return 0 ;
}
