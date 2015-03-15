// File Name: temp.cpp
// Author: darkdream
// Created Time: 2014年09月11日 星期四 15时18分26秒

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
#define maxn 50100
using namespace std;
int hs[1010];
struct Trie
{
    int next[maxn][26],fail[maxn],end[maxn];
    int root, L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        int L = 0 ; 
        root = newnode();
    }
    void insert(char s[],int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i] - 'A'] == -1)
                next[now][s[i] - 'A'] = newnode();
            now = next[now][s[i] - 'A'];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
	}
    void query()
    {
        int now = root ; 
        char c ;
        while(c = getchar())
        {
            if(!(c <= 'Z' && c >= 'A'))
            {
                now = root ; 
                continue;
            }
            now = next[now][c - 'A'];
            int temp = now ; 
            while(temp != root)
            {
                if(end[temp])
                {
                    hs[end[temp]] ++ ; 
                }
                temp = fail[temp];
            }
        }
    }
};
char str[1005][55];
Trie ac;
int main(){
    int n;
    while(scanf("%d",&n) != EOF)
    {
        memset(str,0,sizeof(str));
        ac.init();
        getchar();
        for(int i = 1 ;i <= n;i ++)
        {
            scanf("%s",str[i]);
            getchar();
            ac.insert(str[i],i);
        }
        ac.build();
        memset(hs,0,sizeof(hs));
        ac.query();
        for(int i = 1;i <= n;i ++)
        {
            if(hs[i])
            {
                printf("%s: %d\n",str[i],hs[i]);
            }
        }
    }
    return 0;
}

