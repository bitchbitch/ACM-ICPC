// File Name: temp.cpp
// Author: darkdream
// Created Time: 2014年09月11日 星期四 15时18分4秒

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
#include<queue>
#define LL long long
#define maxn 60002
#define INF  0x3f3f3f3f
using namespace std;
int n,m;
struct Trie
{
    int next[maxn][2],fail[maxn],end[maxn];
    int root, L;
    int newnode()
    {
        memset(next[L],-1,sizeof(next[L]));
        end[L++] = 0 ;
        return L-1;
    }
    void init()
    {
        L = 0 ; 
        root = newnode();
    }
    void insert(char buf[],int status)
    {
        int now = root;
		int len = strlen(buf);
        for(int i = 0 ;i < len ;i ++)
        {
            if(next[now][buf[i] - '0'] ==  -1)
                next[now][buf[i] - '0'] = newnode();
            now = next[now][buf[i] - '0'];
        }
        end[now] = status;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root; 
        for(int i = 0;i < 2;i ++)
        {
            if(next[root][i] == -1)
            {
                next[root][i] = root;  //指向root 是没有问题的，我们主要是通过end 数组对个数进行计数的。    
            }else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0 ;i < 2;i ++)
            {
                if(next[now][i] == -1)
                {
                    next[now][i] =  next[fail[now]][i]; 
                }
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
	int g[11][11];
	int dp[1025][11];
	int cnt;
	int pos[11];
	int dis[60010];
	void bfs(int k )// bfs  因为是直接 bfs  所以没有松弛操作
	{
	    queue<int> q; 
		memset(dis,-1,sizeof(dis));
		dis[pos[k]] = 0 ;
		q.push(pos[k]);
		while(!q.empty())
		{
		   int now = q.front();
		   q.pop();
		   for(int i = 0 ;i < 2; i ++)
		   {
		      int tmp = next[now][i];
			  if(dis[tmp] < 0 && end[tmp] >= 0 )
			  {
			      dis[tmp] = dis[now] +1;
				  q.push(tmp);
			  }
		   }
		}
       for(int i = 0 ;i < cnt; i ++)
		   g[k][i] = dis[pos[i]];
	}
int query()
    {

        pos[0] = 0;
        cnt = 1;
        for(int i = 0;i < L;i++)
            if(end[i] > 0)
                pos[cnt++] = i;
        for(int i = 0; i < cnt;i++)
            bfs(i);

        for(int i = 0;i < (1<<n);i++)
            for(int j = 0;j < cnt;j++)
                dp[i][j] = INF;
        dp[0][0] = 0; //
        for(int i = 0;i <(1<<n);i++)
            for(int j = 0;j < cnt;j++)
                if(dp[i][j]<INF)
                {
                    for(int k = 0;k < cnt;k++)
                    {
                        if(g[j][k] < 0)continue;
                        if( j == k)continue;
                        dp[i|end[pos[k]]][k] = min(dp[i|end[pos[k]]][k],dp[i][j]+g[j][k]);
                    }
                }
        int ans = INF;
        for(int j = 0;j < cnt;j++)
            ans = min(ans,dp[(1<<n)-1][j]);
        return ans;
    }
};
Trie ac;
char str[50005];
int main(){
    while(scanf("%d %d",&n,&m ) != EOF)
    {
	 if(n == 0 && m == 0 )
		 break;
	  ac.init();
	  for(int i = 0;i < n;i ++)
	  {
        scanf("%s",str);
	    ac.insert(str,1<<i);
	  }
	  for(int i = 1;i <= m;i ++)
	  {
	     scanf("%s",str);
		 ac.insert(str,-1);
	  }
	  ac.build();
	  
	  printf("%d\n",ac.query());
	}
    return 0;
}
