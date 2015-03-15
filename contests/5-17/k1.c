#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1000000000
#define LL long long int
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define maxn 120
using namespace std;

int N;
struct node
{
	int id,cost;
	int tar;
} p[maxn];
vector<node> peo[maxn];
int vis[maxn];
vector<node> num;
bool cmp1(node x,node y)
{
	return x.cost>y.cost;
}
bool cmp2(node x,node y)
{
	return x.cost<y.cost;
}

int main()
{
	freopen("/home/plac/problem/input.txt","r",stdin);
	int i,j;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=1; i<=N; i++)
		{
			peo[i].clear();
		}
		num.clear();
		for(i=2; i<=N; i++)
		{
			scanf("%d",&p[i].tar);
			p[i].id=i;
		}
		for(i=2; i<=N; i++)
		{
			scanf("%d",&p[i].cost);
			peo[p[i].tar].push_back(p[i]);
			if(p[i].tar!=1)
			{
				num.push_back(p[i]);
			}
		}
		for(i=1;i<=N;i++)
		{
			sort(peo[i].begin(),peo[i].end(),cmp1);
		}
		sort(num.begin(),num.end(),cmp2);
		int ans=inf;
		for(i=max(1,(int)peo[1].size());i<N;i++)
		{
			memset(vis,0,sizeof(vis));
			int gap=i-peo[1].size();
			int res=0;
			for(j=2;j<=N;j++)
			{
				int temp=peo[j].size();
				while(temp!=0&&temp>=i)
				{
					temp--;
					gap--;
					res+=peo[j][temp].cost;
					vis[peo[j][temp].id]=1;
				}
			}
			if(gap<0)
			{
				continue;
			}
			if(i+(N-1)*(i-1)==N)
			{
				gap=1;
			}
			int cur=0;
			while(gap)
			{
				if(vis[num[cur].id])
				{
					cur++;
				}
				else
				{
					vis[num[cur].id]=1;
					res+=num[cur].cost;
					gap--;
					cur++;
				}
			}
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
