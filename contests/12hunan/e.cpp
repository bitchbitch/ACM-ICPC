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
const int inf = 1 << 30;

int n,m,k,tmp;
int a[20],g[20][20],dist[20],vis[20],s[20];
int work1()
{
	int now ,pos=0,cost=0,MIN=inf;
	for(int i = 0 ; i < tmp; i++ )
	{
		now = s[i] ;   
		dist[now] = inf ;
		vis[now] = 0;
	}  
	dist[1] = 0 ;
	for(int i = 0 ; i < tmp ; i++)
	{
		MIN=inf;
		pos = -1;
		for(int j = 0 ; j < tmp;j++)
		{
			now = s[j] ;
			if(MIN > dist[now] && !vis[now]) 
			{
				MIN = dist[now] ;
				pos = now ;
			}
		}
		if(pos == -1)
			return 0 ; 
		cost += MIN ;  
		vis[pos] = 1;
        //printf("%d\n",pos);	
		for(int j = 0 ; j < tmp; j++)
		{
			now = s[j] ;
			if(dist[now] > g[pos][now])
				dist[now] = g[pos][now] ; 
		}
	}
	int sum = 0;
	for(int i = 0 ; i < tmp ; i++)
	{

		now = s[i] ;
		if(!vis[now])
			return 0 ; 
		sum += a[now] ;
	}
	//printf("***%d\n",sum);
	if(cost <= k )  
		return sum ;
	else  return 0 ; 
}

void  print_subset(int x)
{
	tmp = 1 ;
	s[0] = 1; 
	for(int i=0;i < n-1;i++)
		if(x&(1<<i))
		{
			s[tmp++]=i+2;
		}
}

int main()
{
	int t ,u,v,w;
	scanf("%d",&t) ;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ;j++)
				g[i][j]=inf ;
		for(int i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]) ;   
		for(int i = 1 ; i <= m ; i++)
		{
			scanf("%d%d%d",&u,&v,&w) ;
			g[u][v]=g[v][u]= min(g[u][v],w);       
		}
		int ans = a[1] ;
		int k = 1 << (n-1);
		for(int i= 0; i < k ;i++)
		{
			print_subset(i);
		/*	for(int j = 0 ;j < tmp ;j ++)
				printf("%d ",s[j]);
			printf("\n");
		*/	int ans1 ;
			ans1 = work1() ;
			ans = max(ans,ans1);
		}
		printf("%d\n",ans) ;
	} 
	return 0;
} 
