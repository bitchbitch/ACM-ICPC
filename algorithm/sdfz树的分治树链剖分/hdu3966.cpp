// File Name: spoj375.cpp
// Author: darkdream
// Created Time: 2014年10月09日 星期四 19时50分56秒

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
#define maxn 50006 
using namespace std;
int tr[maxn];
int value[maxn];

int L(int x)
{
	return 2*x;
}
int R(int x)
{
	return 2*x +1;
}
int lowbit(int x)
{
  return x & (-x);
}
int n; 
void update(int x ,int uv)
{
  //printf("%d %d*\n",x,uv);
  while(x <= n+1)
  {
    tr[x] += uv; 
	x += lowbit(x);
  }
}
int getsum(int x)
{
    int sum = 0 ;
	while(x >= 1)
	{
	    sum += tr[x];
	    x -= lowbit(x);
	}
	return sum; 
}
vector<int>  mp[maxn];
int siz[maxn]; // 子节点的个数
int fa[maxn];  // 父亲节点
int son[maxn];  // 儿子节点
int dep[maxn];  // 深度
int top[maxn];  // 
int w[maxn];
int totw;
void dfs_1(int k , int la,int d)
{
	int num = mp[k].size();
	//	printf("%d %d %d\n",k,la,num);
	dep[k] = d; 
	fa[k] = la;
	siz[k] = 1 ;
	son[k] = -1;
	for(int i = 0 ;i < num ;i ++)
	{
		if(mp[k][i] != la)
		{
			dfs_1(mp[k][i],k,d+1);
			siz[k] += siz[mp[k][i]];
			if(son[k] == -1 || siz[mp[k][i]] > siz[son[k]])
				son[k] = mp[k][i] ;
		}
	}
}
void dfs_2(int k,int sp )
{
	top[k] = sp;
//	printf("%d %d\n",k,top[k]);
	if(son[k] != -1){
		w[k] = ++totw;
		dfs_2(son[k],sp);
	}else{
		w[k] = ++totw ; 
		return;
	}
	int num = mp[k].size();
	for(int i = 0;i < num ;i ++ )
	{
		//		printf("%d\n",mp[k][i]);
		if(mp[k][i]!= son[k] && mp[k][i] != fa[k]) 
			dfs_2(mp[k][i],mp[k][i]);	       
	}
}
void make()
{
	totw = 0 ;
	memset(tr,0,sizeof(tr));
	dfs_1(1,0,1);
	//	printf("***\n");
	dfs_2(1,1);

}
void find(int u ,int v,int uv)
{
	int f1 = top[u],f2 = top[v];
	int tmp = 0 ;
	while(f1 != f2)
	{
		if(dep[f1] < dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}
		update(w[f1],uv);
		update(w[u]+1,-uv);
		u = fa[f1]; // f1 是他的top
		f1 = top[u];
	}
	//printf("%d %d**\n",u,v);
	//	printf("%d %d\n",f1,f2);
	if(dep[u] > dep[v])
		swap(u,v);
	update(w[u],uv);
	update(w[v]+1,-uv);
}
int main(){
	int m,q;
    //freopen("out","r",stdin); 
	while(scanf("%d %d %d",&n,&m,&q) != EOF)
	{
		for(int i = 1; i <= n;i ++)
			mp[i].clear();
		for(int i = 1; i <= n;i ++)
	        scanf("%d",&value[i]);	
		int u,v;
		for(int i = 1;i <= m  ;i ++)
		{
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
			  printf("%d\n",value[v] + getsum(w[v]));
			  continue;
			}
		    int w; 
			scanf("%d%d%d",&u,&v,&w);
			if(op[0] == 'I')
			     find(u,v,w);
			else find(u,v,-w);
			/*for(int i = 1;i <= n;i ++)
			{	query(1,i);
				printf(" ");
			}
			printf("\n");*/
		}
	}
	return 0;
}
