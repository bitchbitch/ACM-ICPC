// File Name: e.1.c
// Author: darkdream
// Created Time: 2013年09月06日 星期五 20时03分39秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
LL pp[10] , num[10],zt,row,n,m,dp[34][100000];

void dfs(LL pos, LL status)
{
  if(pos == n)
  {
    dp[row+1][status] += dp[row][zt];
	return;
  }
  if(num[pos] == 0 )
  {
     if(pos + 2 < n  && num[pos+2] == 0  && num[pos+1] == 0 ) dfs(pos+3,status);
	 dfs(pos+1,status+ 2*pp[pos]);
  }
  else if(num[pos] == 1)
     dfs(pos+1,status);
  else {
     dfs(pos+1,status+pp[pos]);
  }
}
void change()
{
  LL now = zt ,k = -1;
  memset(num,0,sizeof(num));
  while(now)
  {
    num[++k] = now%3; 
	now = now/3;
  }

}
int main(){
   pp[0] = 1;
   for(int i = 1;i<= 9;i ++) pp[i] = pp[i-1]*3;

   while(scanf("%lld %lld",&n,&m) && (m||n))
   {
	 if((m*n)%3 != 0  )
	 {
	   printf("0\n");
	   continue;
	 }
     memset(dp,0,sizeof(dp));
	 dp[0][0] = 1; 
	 LL nmax = pp[n];
     for(row = 0 ; row < m ; row ++)
       for(zt = 0 ; zt < nmax; zt ++)
	   if(dp[row][zt])
	   {
	     change();
	     dfs(0,0);
	   }
	 printf("%lld\n",dp[m][0]);
   }
return 0 ;
}
