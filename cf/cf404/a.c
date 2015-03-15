// File Name: a.c
// Author: darkdream
// Created Time: 2014年03月19日 星期三 23时30分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int n ; 
char map[400][400];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ; 
   scanf("%d",&n);
   
   for(int i =1 ;i <= n;i ++)
   {
     scanf("%s",&map[i][1]);
   }
   int ok = 1; 
   char temp = map[1][1];
   char temp1 = map[1][2];
   if(temp1 == temp)
	  ok = 0 ; 
   for(int i = 1;i <= n;i ++)
    {
	   if(map[i][i] != map[i][n-i+1] || map[i][i] != temp)
		    ok = 0 ; 
	   for(int j = 1;j <= n;j ++)
	   {
	      if(j != i && j != n-i+1 && map[i][j] != temp1)
			  ok = 0 ;
	   }
	}
   if(ok)
	   printf("YES\n");
   else printf("NO\n");
    
return 0 ;
}
