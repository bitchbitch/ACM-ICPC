// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月05日 星期日 00时47分32秒

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
int num ; 
void solve(int n)
{
   num = 1; 
   for(int i = 1;i <= n+1;i ++)
   {
     num *= 2; 
   }
   num -- ; 
}
int dp[4000];
int a[4000];
int add[5000];
void dfs(int k,int step)
{
	if(k > num)
		return;
    dfs(2*k,step + 1);
	dfs(2*k+1,step + 1);
	dp[k] = max(dp[2*k] + a[2*k-1],dp[2*k+1] + a[2*k]);
}
int ans = 0 ; 
void findans(int k)
{
	if(k > num )
		return;
	
	int ta = dp[k*2] + a[2*k-1];
	int tb = dp[k*2+1] + a[2*k];
    int tt = abs(ta-tb);
	//printf("%d %d\n",ta,tb);
	ans += tt; 
   findans(2*k);
   findans(2*k+1);

}
int main(){
  int n;
  scanf("%d",&n);
  solve(n);
  for(int i = 1;i< num;i ++)
	  scanf("%d",&a[i]);
  dfs(1,1);
 /* for(int i = 1;i <= num;i ++)
	  printf("%d ",dp[i]);
  puts("\n");*/
  findans(1);
  printf("%d\n",ans);
return 0;
}
