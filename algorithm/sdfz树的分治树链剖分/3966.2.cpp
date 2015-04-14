// File Name: 3966.2.cpp
#pragma comment(linker, "/STACK:1024000000,1024000000")
// Author: darkdream
// Created Time: 2015年04月14日 星期二 11时01分25秒

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
#define maxn 50005
using namespace std;
int sz[maxn];
int fa[maxn];
int son[maxn];
int top[maxn];
int dep[maxn];
int w[maxn];
int totw;
vector<int> mp[maxn];
int tr[maxn];
int val[maxn];
int lowbit(int x)
{
  return x & -x; 
}
int n; 
void update(int x, int uv){
	//printf("%d %d\n",x,uv);
	while(x <= n + 1){
		tr[x] += uv;
		x += lowbit(x);
	}
}
int getsum(int x){
	int sum = 0 ; 
	while(x >= 1)
	{
	   sum += tr[x];
	   x -= lowbit(x);
	}
	return sum ;
}

void dfs_1(int k,int la,int d){
	int num = mp[k].size();
	dep[k] = d; 
	fa[k] = la ; 
	sz[k] = 1; 
	son[k] = -1;
	for(int i = 0 ;i < num ;i ++){
	    if(mp[k][i] != la){
			dfs_1(mp[k][i],k,d+1);
			sz[k] += sz[mp[k][i]];
			if(son[k] == -1 || sz[mp[k][i]] > sz[son[k]])
				son[k] = mp[k][i];
		}
	}
}
void dfs_2(int k ,int sp)
{
   top[k] = sp ; 
   if(son[k] != -1){
	   w[k] = ++ totw ;
	   dfs_2(son[k],sp);
   }else{ 
	   w[k] = ++totw;
	   return ;
   }
   int num = mp[k].size(); 
   for(int i = 0 ;i < num ;i ++){
		if(mp[k][i] != son[k] && mp[k][i] != fa[k]){
			dfs_2(mp[k][i],mp[k][i]);
		}
   }
}
void make(){
	totw = 0 ; 
	memset(tr,0,sizeof(tr));
	dfs_1(1,0,1);
	dfs_2(1,1);
}
void find(int u ,int v,  int uv){
	int f1 = top[u],f2= top[v];
	int tmp = 0 ; 
	while(f1 != f2){
		if(dep[f1] < dep[f2])
		{
	        swap(u,v);
			swap(f1,f2);
		}
		update(w[f1],uv);
		update(w[u]+1,-uv);
		u = fa[f1];
		f1 = top[u];
	}
	if(dep[u] > dep[v]){	
		swap(u,v);
	}
	update(w[u],uv);
	update(w[v]+1,-uv);
}//不停的更新u,v，一直到在同一条链上
int main(){
	int m , q; 
	while(scanf("%d %d %d",&n,&m,&q) != EOF){
		for(int i = 1;i <= n;i ++)
			mp[i].clear();
		for(int i = 1;i <= n;i ++)
			scanf("%d",&val[i]);
		int u,v; 
		for(int i = 1;i < n;i ++){
			scanf("%d %d",&u,&v);
			mp[v].push_back(u);
			mp[u].push_back(v);
		}
		make();
		char op[10];
		while(q--)
		{
			scanf("%s",op);
			if(op[0] == 'Q'){
				scanf("%d",&v);
	            printf("%d\n",val[v] + getsum(w[v]));
				continue;
			}
			int add; 
			scanf("%d %d %d",&u,&v,&add);
			if(op[0] == 'I')
				find(u,v,add);
			else find(u,v,-add);
		}
	}
return 0;
}
