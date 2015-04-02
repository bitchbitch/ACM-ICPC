// File Name: 161d.cpp
// Author: darkdream
// Created Time: 2014年08月03日 星期日 19时20分10秒

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

using namespace std;

vector<int> a[10004];
int m[50005][500];
int visit[10004];
int n , k ;
LL ans = 0 ;
void dfs(int t)
{
    int lt = a[t].size();
    m[t][0] = 1; 
    for(int i= 0 ;i < lt ;i ++)
    {
        int tt = a[t][i];
        if(!visit[tt])
        {
            visit[tt] = 1;
            dfs(tt);
            for(int j =0 ;j < k;j ++)
                ans += m[t][k-j-1] * m[tt][j];
            for(int j = 0 ;j < k;j ++)
            {
                m[t][j+1] += m[tt][j];
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&k);
    int ta,tb;
    memset(m,0,sizeof(m));
    memset(visit,0,sizeof(visit));
    for(int i =1 ;i <= n-1;i ++)
    {
        scanf("%d %d",&ta,&tb);
        a[ta].push_back(tb);
        a[tb].push_back(ta);
    }
    visit[1] = 1; 
    dfs(1);
    printf("%I64d\n",ans);
    return 0;
}
