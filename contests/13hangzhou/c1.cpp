// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年05月07日 星期三 17时07分23秒

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

using namespace std;
#define MAXN  200005


int a[MAXN];
struct lr{
	int l,r,num;
}q[MAXN];
int cmp(lr a, lr b)
{
	return a.l > b.l;
}
int tree[MAXN];
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int l,int k)
{
	int sum = 0 ; 
	while(k >= 1 )
	{
		sum += tree[k];
		k -= lowbit(k);
	}
	return sum ; 
}
int n;
int hs[MAXN];
void update(int k  ,int v )
{
	//	printf("%d\n",k);
	while(k <= n)
	{
		tree[k] += v; 
		k += lowbit(k);
	}

}
int ans[MAXN];
int prime[MAXN][20];
int num[MAXN];
int last[MAXN];
void solve(){
	memset(num,0,sizeof(num));
	memset(hs,0,sizeof(hs));
	for(int i = 2 ;i <= 200000;i ++)
	{
		if(hs[i] == 0 )
		{
			int k = i;
			while(k <= 200000)
			{
				num[k] ++ ; 
				prime[k][num[k]] = i ; 
				hs[k] = 1; 
				k += i ;
			}
		}
	}
}
int isupdate[MAXN];
int cmp1(int a, int b)
{
	return a < b ;
}
int main(){
	//freopen("intpu.in","r",stdin);
	int m ;
	solve();
	//printf("***\n");
	while(scanf("%d %d", &n,&m) != EOF)
	{
		if(n == 0 && m == 0 )
			break;
		memset(tree,0,sizeof(tree));
        memset(q,0,sizeof(q));
		
		
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		for(int i = 1;i <= m;i ++)
		{
			scanf("%d %d",&q[i].l,&q[i].r);
			q[i].num = i; 
		}
		sort(q+1,q+m+1,cmp);
		
		int p = 1;
		memset(hs,0,sizeof(hs));
		memset(last,0,sizeof(last));
		memset(isupdate,0,sizeof(isupdate));
		for(int i = n;i >= 1 ;--i)
		{
			int ta[20];
			int tanum = 0 ; 
			memset(ta,0,sizeof(ta));
			for(int j = 1; j <= num[a[i]]; ++j )
			{
				int temp = prime[a[i]][j];
				if(hs[temp])
				{
					tanum ++ ; 
					ta[tanum] = hs[temp];
				}
				hs[temp] = i ; 
			}
			if(tanum)
			{
				sort(ta+1,ta+tanum+1,cmp1);
				int min = ta[1];
				for(int j = 1;j <= tanum;j ++)
				{
					if(ta[j]!= ta[j-1])
					{
						if(last[ta[j]])
						{
							update(last[ta[j]],-1);
							update(ta[j],1);
							last[ta[j]] = 0 ; 
               			}else {
						      if(!isupdate[ta[j]])
							  {
							     update(ta[j],1);
								 isupdate[ta[j]] = 1 ; 
							  }
						}
					   if(ta[j] < min)
						  min = ta[j];
					}
				}
			    update(min,1);
				isupdate[min] = 1; 
				last[i] = min;
				isupdate[i] = 1;

			}
			while(q[p].l == i )
			{
				ans[q[p].num] = (q[p].r - q[p].l +1) - getsum(q[p].l,q[p].r);
				p++;
			}
		}
		for(int i = 1;i <= m;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}

