#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;
const int inf = 1>>20 ;

int n,m,k;
int a[100],g[50][50],dist[100],vis[100];


int work1(int s[],int len)
{
	int now ,pos=0,cost=0,MIN;
	for(int i = 0 ; i < len; i++ )
	{
		now =s[i] ;   
		dist[now] = g[1][now] ;
		vis[now]=0;
	}
	vis[1]=1;
	for(int i = 1 ; i < len ; i++)
	{
		MIN=inf ;
		for(int j = 0 ; j < len;j++)
		{
			now = s[j] ;
			if(MIN > dist[now] && !vis[now]) 
			{
				MIN=dist[now] ;
				pos=now ;
			}
		}
		cost += MIN ;  
		vis[pos]=1;
		for(int j = 0 ; j < len; j++)
		{
			now= s[j] ;
			if(dist[now] > g[pos][now] && !vis[now])
				dist[now] = g[pos][now] ; 
		}
	}
	int sum = 0;
	for(int i = 0 ; i < len ; i++)
	{   now = s[i] ;
		sum += a[now] ;
	}
	if(cost <= k )
		return sum ;
	else  return 0 ; 
}

int main()
{
	int t ,u,v,w;
	int s1[100],s2[100] ; 
	scanf("%d",&t) ;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(g,0,sizeof(g));
		for(int i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]) ;   
		for(int i = 1 ; i <= m ; i++)
		{
			scanf("%d%d%d",&u,&v,&w) ;
			g[u][v]=g[v][u]=w ;       
		}
		int ans = 0 ,tmp=1;
		s2[0]=1;
		for(int j = 2 ; j <= n ; j++)
		{
			s1[tmp++]=j ;	   	         	  
			s2[1]=j;
			int ans1 = work1(s1,tmp) ;
			int ans2 = work1(s2,2) ;
			if(ans1)
				ans = max(ans,ans1);
			if(ans2)
				ans = max(ans,ans2) ;  
		}

		if(ans == 0 ) 
			printf("%d\n",a[0]) ;
		else printf("%d\n",ans) ;
	} 
	return 0;
} 
