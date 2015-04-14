// File Name: poj1741.cpp
// Author: darkdream
// Created Time: 2014年10月05日 星期日 09时49分58秒

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
#define maxn 10005
using namespace std;
int n , m ; 
struct node{
	int ne;
	int dis; 
	node(int _ne,int _dis)
	{
		ne = _ne;
		dis = _dis;
	}
};
vector<node> mp[maxn];
int dn = 0; 
int vis[maxn];
int dis[maxn];
int sum[maxn];
int mx[maxn];

void getsize(int k , int la)
{
	sum[k] = 1;
	mx[k] = 0;
	int num = mp[k].size();
	for(int i = 0;i < num ;i ++)
	{
		if(!vis[mp[k][i].ne] && mp[k][i].ne != la)
		{
			getsize(mp[k][i].ne,k);
			mx[k] = max(sum[mp[k][i].ne],mx[k]);
			sum[k] += sum[mp[k][i].ne];
		}
	}
}
int root;
int mxv;
void getroot(int k ,int la,int tans)
{
	int tt = max(tans - sum[k] ,mx[k]);
	if(tt <  mxv)
	{
	//   printf("****%d\n",k);
		mxv = tt; 
		root = k ; 
	}
	int num = mp[k].size();
	for(int i = 0 ;i < num ;i ++)
	{
		if(!vis[mp[k][i].ne] && mp[k][i].ne != la)
		{
			getroot(mp[k][i].ne,k,tans);
		}
	}
}
void getdis(int k , int la,int tdis)
{
	dis[dn] = tdis;
	dn ++ ;
	int num = mp[k].size();
	for(int i = 0 ;i < num ;i ++)
	{
		if(mp[k][i].ne != la && !vis[mp[k][i].ne]) 
		{
			getdis(mp[k][i].ne,k,tdis + mp[k][i].dis);
		}
	}
}
int getans(int l ,int r )
{
	sort(dis+l,dis+r);
	int ans = 0 ; 
	r = r-1;
	while(r > l)
	{
		if(dis[l] + dis[r] <= m)
		{
			ans += r - l ; 
			l ++ ;
		}else {
			r-- ;
		}
	}
	return ans;
}
int solve(int k)
{
//	printf("%d**\n",k);
	root = k ; 
	getsize(k,0);
	mxv = 1e9;
	getroot(k,0,sum[k]);
	k = root;
	//printf("%d %d\n",k,sum[k]);
	dn = 1 ; 
	dis[0] = 0;
	int tans = 0 ; 
	int j ;
	int num = mp[k].size();
	for(int i = 0 ;i < num ;i ++)
	{
		if(!vis[mp[k][i].ne])
		{
			j = dn;
			getdis(mp[k][i].ne,k,mp[k][i].dis);
			tans += getans(j,dn);
	//		printf("%d %d %d\n",tans,j,dn);
		}
	}
	int ans = getans(0,dn) - tans;
/*	printf("ans = %d\n",ans);
	for(int i = 0 ;i < dn ;i++)
		printf("%d ",dis[i]);
	printf("\n");
	printf("ans = %d\n",ans);
*/
	vis[k] = 1;  //删除这个点

	for(int i = 0 ;i < num ;i ++)
	{
		if(!vis[mp[k][i].ne])
		{
			ans += solve(mp[k][i].ne);
		}
	}
	return ans;
}
int main(){
	//freopen("out","r",stdin);
	while(scanf("%d %d",&n,&m) != EOF)
	{
		if(n == 0 && m == 0 )
			break;
		int u,v,w;
		for(int i = 1;i <= n;i ++)
			mp[i].clear();
		for(int i = 1;i < n;i ++)
		{
			scanf("%d %d %d",&u,&v,&w);
			mp[u].push_back(node(v,w));
			mp[v].push_back(node(u,w));
		}
		memset(vis,0,sizeof(vis));
		printf("%d\n",solve(1));
	}
	return 0;
}
