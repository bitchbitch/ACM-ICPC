// File Name: 2533.c
// Author: darkdream
// Created Time: 2013年07月24日 星期三 19时43分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int a[10005];
int dp[10005];


int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n;
   while(scanf("%d",&n) != EOF)
   { 
	   
	   memset(a,0,sizeof(a));
	   memset(dp,0,sizeof(dp));
	   for(int i = 1;i <= n;i ++)
		   scanf("%d",&a[i]);
	   int max =0 ;
	   for(int i = 1; i <= n;i ++)
	   {
	       for(int j = 1; j < i ; j ++)
		   {
		     if(a[i] > a[j])
			 {
			   if(dp[j] + 1  > dp[i])
				   dp[i] = dp[j]+1;
			 }
		   }
		   if(dp[i] > max)
			   max = dp[i];
	   }
	   printf("%d\n",max+1);
       	
   }
return 0 ;
}
