// File Name: 126b.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 15时23分51秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

using namespace std;
char str[1000005];
int dp[1000005];
int hs[1000005];
void getnext(char *p,int next[])
{
   int pLen =strlen(p);
   next[0] = -1;
   int k = -1;
   int j = 1; 
   while(j < pLen )
   {
     if(k == -1 || p[j] == p[k+1])
	 {
	  if(p[j] == p[k+1])
	  {
	     next[j] = k + 1; 
		 k ++;
		 j ++ ; 
	  }else{
	     next[j] = -1;
         j++;
	  }
	 }
	 else {
	    k = next[k] ;
	 }
   }
}
int main(){
   scanf("%s",str);
   getnext(str,dp);
   int len = strlen(str);
   for(	int i = 0;i < len; i++)
   {
	 /*if(dp[i] == 0 && str[i] == str[0])
	 {
	 
	 }
	 else
	   dp[i]--;
	 *///printf("%d ",dp[i]);
	   if(dp[i] != -1)
	   hs[dp[i]] ++; 
   }
   if(dp[len-1] != -1)
      hs[dp[len-1]] -- ; 
   while(hs[dp[len-1]] ==0 && dp[len-1] != -1)
   {
  //     printf("dp[len-1] = %d\n",dp[len-1]);
	   dp[len-1] = dp[dp[len-1]];
   }
  // printf("ans = %d\n",dp[len-1]);
   int an = 0 ; 
   for(int i = len -2;i >= 1;i --)
	   if(dp[i] == dp[len -1])
	   {
		   an = 1 ; 
	   }
   if(an == 0 || dp[len -1] == -1 || (dp[len-1] ==0 && str[len-1] != str[0]))
   {
	   printf("Just a legend\n");
	   return 0 ; 
   }
   for(int i =0 ;i <= dp[len-1];i ++)
	   printf("%c",str[i]);

return 0;
}
