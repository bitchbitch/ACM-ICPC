#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int>node[100005];
int dp[100005][2],vist[100005],val[100005];
int max(int a,int b)
{
    return a>b?a:b;
}
void dfs(int p)
{
    dp[p][0]=0; dp[p][1]=val[p];
    vist[p]=1;
    int len=node[p].size();
    for(int i=0;i<len;i++)//进行len次dp,dp[p][0]表示不选择该条边时的最大值，dp[p][1]表示选择该边时的最大值
    {
        int son=node[p][i];
        if(vist[son]) continue;//如果子节点已被访问
        dfs(son);//递归
        dp[p][1]+=dp[son][0];//选择这条边
        dp[p][0]+=max(dp[son][0],dp[son][1]);
    }
}
int main()
{
    int n,a,b,MAX;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);vist[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(1);
    MAX=dp[1][0];
    MAX=max(MAX,dp[1][1]);
    printf("%d\n",MAX);
}
