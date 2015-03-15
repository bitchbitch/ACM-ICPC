// File Name: 505b.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 10时38分29秒

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
int dp[105][105][105]; 
struct node{
  int ne,co;
  node()
  {}
  node(int _ne,int _co)
  {
    ne = _ne;
	co = _co;
  }
};
vector<node> mp[105];
int n, m,q;
void dfs(int be,int k,int co)
{
	//if(be == 3 )
	//	printf("%d %d %d\n",be,k,co);
    for(int i = 0;i < mp[k].size();i ++)
	{
	  if((mp[k][i].co == co || co == 0) && dp[be][mp[k][i].ne][mp[k][i].co] == 0 && mp[k][i].ne != k)
	  {
	    dp[be][mp[k][i].ne][co] = 1; 
		//printf("*%d %d %d\n",be,mp[k][i].ne,co);
		dfs(be,mp[k][i].ne,mp[k][i].co);
	  }
	}
}
int main(){
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= m;i++) 
   {
      int ta,tb,tc;
	  scanf("%d %d %d",&ta,&tb,&tc);
	  mp[ta].push_back(node(tb,tc));
	  mp[tb].push_back(node(ta,tc));
   }
   for(int i = 1;i <= n;i ++ )
   {
	 dfs(i,i,0);
   }
   scanf("%d",&q);
   for(int i =1;i <= q;i ++)
   {
     int ta,tb;
	 scanf("%d %d",&ta,&tb);
	 int sum = 0; 
	 for(int j = 1;j <= m ;j ++)
	 {
	   sum += dp[ta][tb][j];
	 }
	 printf("%d\n",sum);
   }
return 0;
}
