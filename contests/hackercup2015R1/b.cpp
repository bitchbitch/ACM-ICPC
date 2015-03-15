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
#define maxn 1001005
using namespace std;
struct Trie
{
	int next[maxn][26],end[maxn];
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
	int insert(char buf[])
	{
		int now = root;
		int len = strlen(buf);
		int rans = -1;
		for(int i = 0 ;i < len ;i ++)
		{
			if(next[now][buf[i] - 'a'] ==  -1)
			{
				next[now][buf[i] - 'a'] = newnode();
				if(rans == -1)
					rans = i ; 
			}
			now = next[now][buf[i]- 'a'];
		}
		end[now] = 1;
		if(rans == -1)
			return len;
		else return rans + 1;
	}
};
char buf[1010005];
Trie ac;
int main(){
	freopen("autocomplete.txt","r",stdin);
	freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ca ++)
	{
	    int n ;
		scanf("%d",&n);
		ac.init();
		int ans = 0; 
		for(int i = 1;i <= n;i ++)
		{	
			scanf("%s",buf);
			ans += ac.insert(buf);
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
