// File Name: 459e.cpp
// Author: darkdream
// Created Time: 2015年03月13日 星期五 16时40分26秒

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
#define maxn 300005
using namespace std;
int n , m; 
struct node{  
	int l ,r , v; 
}mp[maxn];
LL dp[maxn];
int mx[maxn];
int mxc[maxn];
int cmp(node a, node b)
{
   return a.v < b.v ;
}
stack <int > si ;
stack <LL > val ; 
int main(){
   scanf("%d %d",&n,&m);
   for(int i= 1;i <= m;i++)
   {
      scanf("%d %d %d",&mp[i].l,&mp[i].r,&mp[i].v);
   }
   stable_sort(mp+1,mp+1+m,cmp);

   for(int i = 1;i <=m;)
   {
	   LL tmpa,tmpb;
	   int j ; 
	   for(j = i ; mp[j].v == mp[i].v; j  ++)
		  {
		      si.push(mp[j].r);
			  val.push(dp[mp[j].l]+1);
		  }
	   i = j;
	   while(!si.empty())
	   {
	      int p = si.top();
		  si.pop();
		  LL vv = val.top();
		  val.pop();
		  dp[p] = max(vv,dp[p]);
	   }
   }
   LL ans = 0 ; 
   for(int i = 1;i <= n;i ++)
   {
     ans = max(ans,dp[i]);
   }
   printf("%I64d\n",ans);
return 0;
}
