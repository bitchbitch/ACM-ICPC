// File Name: range.c
// Author: darkdream
// Created Time: 2014年04月07日 星期一 17时23分06秒
/*
ID: dream.y1
PROG: range
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int map[300][300];
int hang[300][300];
int lie[300][300];
int dp[4][251][251];
int main(){

   freopen("range.in","r",stdin);
   freopen("range.out","w",stdout);
   
	
   int n ; 
   scanf("%d",&n);
   memset(hang,0,sizeof(hang));
   memset(lie,0,sizeof(lie));
   memset(dp,0,sizeof(dp));
   for(int i =1 ;i <= n;i ++)
	  for(int j = 1;j <= n;j ++)
		  scanf("%1d",&map[i][j]);
   for(int i = 1;i <= n;i ++)
   {
     for(int j = 1;j <= n;j ++)
	 {
	   if(map[i][j])
		   hang[i][j] = hang[i][j-1] + 1;
	 }
   }
   for(int i = 1;i <= n;i ++)
   {
     for(int j = 1;j <= n;j ++)
	 {
	   if(map[j][i])
		   lie[j][i] = lie[j-1][i] + 1;
	 }
   }
   int ans[300];
   memset(ans,0,sizeof(ans));
   for(int i = 2; i <= n;i ++)
   {
     for(int j = 2;j <= n; j ++)
     {
          int k = hang[i][j] > lie[i][j]?lie[i][j]:hang[i][j];
		  if(map[i-1][j-1])
			  dp[1][j-1][1] = 1; 

		  for(int s = 2;s <= k ; s ++ )
			  dp[2][j][s] += dp[1][j-1][s-1];

     }
	    for(int j = 2;j <= n;j ++)
		  for(int s = 2;s <= n;s ++)
		   {
		      ans[s] +=  dp[2][j][s];
		   }

		   memcpy(dp[1],dp[2],sizeof(dp[2]));
		   memcpy(dp[2],dp[3],sizeof(dp[3]));
   }

  for(int i =2;i <= n;i ++)
	  if(ans[i])
		  printf("%d %d\n",i,ans[i]);
return 0 ;
}
