// File Name: stamps.c
// Author: darkdream
// Created Time: 2014年01月14日 星期二 21时19分04秒
/*
ID: dream.y1
PROG: stamps
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int dp[2000001];
int a[51];
int main(){
   freopen("stamps.in","r",stdin);
   //freopen("stamps.out","w",stdout);
   int n , k ; 
   scanf("%d %d",&k,&n);
   memset(dp,0,sizeof(dp));
   for(int i = 1;i <= n;i ++)
   {
    scanf("%d",&a[i]);
	dp[a[i]] = 1; 
   }
   int i; 
   for(i = 1;;i ++)
   {
      int min = 300;
      if(!dp[i])
	  {
	    for(int j = 1;j <= n;j ++)
		{
		  if(i - a[j] >= 1)
			 if(dp[i-a[j]] + 1 < min)
				 min = dp[i-a[j]] + 1; 
		}
		if(min > k)
			break;
		else dp[i] = min;
	  }
   }
   printf("%d\n",i-1);
return 0 ;
}
