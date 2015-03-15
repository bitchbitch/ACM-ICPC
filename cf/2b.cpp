// File Name: 2b.cpp
// Author: darkdream
// Created Time: 2014年08月02日 星期六 15时17分39秒

#pragma comment(linker, "/STACK:102400000,102400000")
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
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL long long
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")

struct node2{
    LL n2 ; 
	LL n5 ;
    bool d;
};
struct node{
   node2 m[2]; 
}dp[1004][1004];
LL l2[100];
LL l5[100];
int nl2;
int nl5;
void init()
{
   memset(dp,0,sizeof(dp));
   l2[1] = 2; 
   l5[1] = 5;
   for(int i = 2;;i ++)
   {
      l2[i] = l2[i-1]*2;
      if(l2[i] > 1e9)
	  {
	     nl2 = i ; 
		 break;
	  }
   }
   for(int i = 2;;i ++)
   {
      l5[i] = l5[i-1]*5;
      if(l5[i] > 1e9)
	  {
	     nl5 = i ; 
		 break;
	  }
   }
}
void solve(int x,int y ,LL t)
{
	int t2 ; 
	int t5 ;
    for(int i =1 ;;i ++)
	{
	   if(t % l2[i] != 0 )
	   {
		   t2 = i-1;
	       break;
	   }
	}
    for(int i =1 ;;i ++)
	{
	   if(t % l5[i] != 0 )
	   {
		   t5 = i-1;
	       break;
	   }
	}
	dp[x][y].m[0].n2 = t2;
	dp[x][y].m[0].n5 = t5;
	dp[x][y].m[1] = dp[x][y].m[0];
}
int num;
bool ans[2000004] = {0};
bool d;
void findway(int x, int y )
{
	num --;
	if((x == 1 && y == 1))
		return;
	
    if(dp[x][y].m[d].d)
	{
	  ans[num] = 1;
	  findway(x,y-1);
	  return;
	}else{
	  findway(x-1,y);
	  return;
	}
}
void dp_clear(int x, int y)
{
	dp[x][y].m[0].n2 = 1e9;
	dp[x][y].m[0].n5 = 1e9;
	dp[x][y].m[0].d = 0;
	dp[x][y].m[1] = dp[x][y].m[0];
}
LL a[1005][1005];
int main(){
   int n ;
   init();
   scanf("%d",&n);
   num = 2*n-1;
   int ok = 0;
   int x, y;
   for(int i = 1;i <= n;i ++)
	   for(int j = 1;j <= n ;j ++ )
	   {

	      LL temp ; 
		  scanf("%I64d",&a[i][j]);
		  if(a[i][j] != 0 )
            solve(i,j,a[i][j]);
		  else{
		    ok = 1;
			x = i; 
			y = j;
		  }
	   }
   for(int i = 2;i <= n;i ++)
   {
      dp[1][i].m[0].n2 = dp[1][i-1].m[0].n2 + dp[1][i].m[0].n2;
      dp[1][i].m[0].n5 = dp[1][i-1].m[0].n5 + dp[1][i].m[0].n5;
	  dp[1][i].m[0].d = 1; 
	  dp[1][i].m[1] = dp[1][i].m[0]; 
   }
   for(int i = 2;i <= n;i ++)
   {
      dp[i][1].m[0].n2 = dp[i-1][1].m[0].n2 + dp[i][1].m[0].n2;
      dp[i][1].m[0].n5 = dp[i-1][1].m[0].n5 + dp[i][1].m[0].n5;
	  dp[i][1].m[1] = dp[i][1].m[0]; 
   }
   for(int i =2;i <= n;i ++)
	   for(int j = 2;j <= n;j ++)
	   {
		   if(a[i][j] == 0 )
		   {
			 dp_clear(i,j);
		     continue;
		   }
	       if(dp[i-1][j].m[0].n2 < dp[i][j-1].m[0].n2)
		   {
		       dp[i][j].m[0].n2 += dp[i-1][j].m[0].n2;
		       dp[i][j].m[0].n5 += dp[i-1][j].m[0].n5;
		   }else{
		       dp[i][j].m[0].n2 += dp[i][j-1].m[0].n2;
		       dp[i][j].m[0].n5 += dp[i][j-1].m[0].n5;
			   dp[i][j].m[0].d = 1; 
		   }
	       if(dp[i-1][j].m[1].n5 < dp[i][j-1].m[1].n5)
		   {
		       dp[i][j].m[1].n2 += dp[i-1][j].m[1].n2;
			   dp[i][j].m[1].n5 += dp[i-1][j].m[1].n5;
		   }else{
		       dp[i][j].m[1].n2 += dp[i][j-1].m[1].n2;
		       dp[i][j].m[1].n5 += dp[i][j-1].m[1].n5;
			   dp[i][j].m[1].d = 1; 
		   }
	   }
   LL T = min(min(dp[n][n].m[0].n2,dp[n][n].m[0].n5),min(dp[n][n].m[1].n2,dp[n][n].m[1].n5));
   if(ok)
   {
      if(T!= 0 )
	  {
		printf("1\n");
	    for(int i = 1;i < x;i ++)
			printf("D");
		for(int i = 1;i < n;i ++)
			printf("R");
		for(int i = x+1;i <=n;i ++)
			printf("D");
		printf("\n");
		return 0 ; 
	  }
   }
   printf("%I64d\n",T);
   d = 0; 
   if(min(dp[n][n].m[0].n2,dp[n][n].m[0].n5) > min(dp[n][n].m[1].n2,dp[n][n].m[1].n5))
   { 
	   d = 1;
	   findway(n,n);
   }
   else findway(n,n);
   for(int i = 1;i <= 2*n-2;i++)
	   if(ans[i])
		   printf("R");
	   else printf("D");
   printf("\n");
return 0;
}
