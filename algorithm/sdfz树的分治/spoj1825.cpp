// File Name: spoj1825.cpp
// Author: darkdream
// Created Time: 2014年10月05日 星期日 20时20分33秒

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
#define maxn 200015
using namespace std;
struct node{
	int ne;
	int w;
	node(int _ne,int _w)
	{
		ne = _ne ; 
		w = _w;
	}
};
int n ,K, m ; 
int col[maxn];
int vis[maxn];
vector <node> mp[maxn];
int sum[maxn];
int mx[maxn];
int cnum[maxn];
void getsize(int k,int la)
{
    sum[k] = 1; 
	mx[k] = 0;
	int num = mp[k].size();
	int tt = 0 ;
	for(int i = 0 ;i < num;i ++)
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
int getroot(int k,int la ,int tans)
{
     int tt = max(tans - sum[k],mx[k]);
	 if(tt < mxv)
	 {
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
LL ans = 0 ;
LL dp[maxn];
LL tdp[maxn];
bool cmp(node a, node b)
{
    return cnum[a.ne] < cnum[b.ne];
}
void getdep(int k ,int la,int tc,LL dep)
{ 
	int st = (col[k] == 1?1:0) ;
	tdp[tc+st] = max(tdp[tc+st],dep); //这个点是G点的时候
	int num = mp[k].size();
	for(int i = 0 ;i < num ;i ++)
	{
		if(!vis[mp[k][i].ne] && mp[k][i].ne != la )
		{
			getdep(mp[k][i].ne,k,tc + st,dep + mp[k][i].w);
		}
	}
}
void getcnum(int k ,int la)
{
	if(col[k])
		cnum[k] = 1; 
	else cnum[k] = 0 ; 
	int tt = 0 ;
	int num = mp[k].size();
	for(int i = 0 ;i < num;i ++)
	{
	   if(!vis[mp[k][i].ne] && mp[k][i].ne != la)
	   {
	       getcnum(mp[k][i].ne,k);
	      if(cnum[mp[k][i].ne] > tt)
			  tt = cnum[mp[k][i].ne];
	   }
	}
	cnum[k] += tt;
}
void solve(int k)
{
	getsize(k,0);
	mxv = 1e9;
	getroot(k,0,sum[k]);
	k = root;
    
	getcnum(k,0);	
	//printf("*****%d %d\n",k,cnum[k]);	
	int num = mp[k].size();
	memset(dp,0,(cnum[k]+3)*sizeof(LL));
	int tk ;
	int st = 0 ;
	if(col[k])
	{
        tk = K + 1;
		st = 1;
	}
	else tk = K ;
    int la =0 ; 
	//int size = min(cnum[k],K);
	sort(mp[k].begin(),mp[k].end(),cmp);
	for(int i = 0 ;i < num ;i ++)
	{
		if(vis[mp[k][i].ne])
			continue;
		
		memset(tdp,0,(cnum[mp[k][i].ne]+3)*sizeof(tdp[0]));
		if(col[k])
		   getdep(mp[k][i].ne,k,1,mp[k][i].w);		
		else 
		   getdep(mp[k][i].ne,k,0,mp[k][i].w);		
	//	printf("**********%d\n",tk);
	    
		
		int tt = min(cnum[mp[k][i].ne]+st,K);	
//		printf("%d %d\n",cnum[mp[k][i].ne]+st,K);
		for(int j = st ;j <= tt;j ++)
		{
		   if(tk - j <= la)
		   {
			if(tdp[j] + dp[tk-j]> ans)
			{
				ans = tdp[j] + dp[tk-j];
			}
		   }else{
			 if(tdp[j] + dp[la]> ans)
			 {
				ans = tdp[j] + dp[la];
			 }
		   }
		} 
		dp[0] = max(dp[0],tdp[0]);
		//printf("%d %d\n",n,cnum[mp[k][i].ne]);
		/*if(tdp[tt+st+1] != 0)
		{
		  printf("&&&&&&&&&&&&&&\n");
		}*/
		for(int j = 1 ;j <= tt+st; j ++)
		{
			dp[j] = max(dp[j],tdp[j]);
			dp[j] = max(dp[j],dp[j-1]);
		}
   //     for(int j = 0;j <= K;j ++)
	//		printf("%lld ",dp[j]);
	//	puts("");
		la = tt + st;
	}
	//puts("**********8");
	vis[k] = 1;
	for(int i = 0;i < num;i ++)
	{
		if(!vis[mp[k][i].ne])
			solve(mp[k][i].ne);
	}
	return; 
}
int main(){
   //freopen("out","r",stdin);	
   //freopen("output.txt","w",stdin);
   while(scanf("%d %d %d",&n,&K,&m) != EOF){
	int temp ; 
	memset(vis,0,sizeof(vis));
	memset(col,0,sizeof(col));
	for(int i = 1;i <= n;i ++)
		mp[i].clear();
	for(int i = 1;i <= m;i ++)
	{
		scanf("%d",&temp);
		col[temp]  = 1;  
	}
	for(int i = 1;i <= n - 1;i ++)
	{
		int a, b , w; 
		scanf("%d %d %d",&a,&b,&w);
		mp[a].push_back(node(b,w));
		mp[b].push_back(node(a,w));
	}
	ans = 0; 
	solve(1);
	printf("%lld\n",ans);
   }
	return 0;
}
