#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
const int N=100010;

int n,m,Q;
int tim;

int num[N],siz[N],top[N],son[N];
int deep[N],p[N],rank[N],fa[N];
int head[N],to[2*N],next[2*N],edge;

void Init()
{
    memset(head,-1,sizeof(head));
    memset(son,-1,sizeof(son));
    tim=0;
    edge=0;
}
void addedge(int u,int v)
{
    to[edge]=v,next[edge]=head[u],head[u]=edge++;
    to[edge]=u,next[edge]=head[v],head[v]=edge++;
}

//树链剖分部分
void dfs1(int u,int father,int d)
{
    deep[u]=d;
    fa[u]=father;
    siz[u]=1;
    for(int i=head[u];~i;i=next[i])
    {
        int v=to[i];
        if(v!=father)
        {
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
}

void dfs2(int u,int tp)
{
    top[u]=tp;
    p[u]=++tim;
    rank[p[u]]=u;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    for(int i=head[u];~i;i=next[i])
    {
        int v=to[i];
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}

//线段树部分
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int value[4*N],col[4*N],MAX[4*N],Mcol[4*N];

void PushUP(int rt)
{
    value[rt]=max(value[rt<<1],value[rt<<1|1]);
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}

void PushDown(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1]+=col[rt];
        col[rt<<1|1]+=col[rt];
        value[rt<<1]+= col[rt];
        value[rt<<1|1]+=col[rt];
        col[rt]=0;
    }
	if(Mcol[rt])
	{
        Mcol[rt<<1]+=Mcol[rt];
        Mcol[rt<<1|1]+=Mcol[rt];
        MAX[rt<<1]+= Mcol[rt];
        MAX[rt<<1|1]+= Mcol[rt];
        Mcol[rt]=0;
	}
}
void Build(int l,int r,int rt)
{
    col[rt]=0;
	value[rt]= 0 ;
	MAX[rt] = 0 ;
	Mcol[rt] = 0;
    if(l==r)
    {
        return;
    }
    int mid=(l+r)>>1;
    Build(lson);
    Build(rson);
    PushUP(rt);
}
void Update(int L,int R,int v,int l,int r,int rt,int st)
{
    if(L<=l&&R>=r)
    {
		if(st)
		{
        col[rt]+=v;
        value[rt]+=v;
		}else{
         MAX[rt]+=v;
         Mcol[rt]+=v;
		}
        return;
    }
    PushDown(rt,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
        Update(L,R,v,lson,st);
    if(R>mid)
        Update(L,R,v,rson,st);
    PushUP(rt);
}
int ans[N];
int Query(int l,int r,int rt,int val)
{
    if(l==r)
	{
		ans[l] = MAX[rt];
        return value[rt];
	}
    PushDown(rt,r-l+1);
    int mid=(l+r)>>1;
    int ret=0;
    if(val<=mid) ret=Query(lson,val);
    else         ret=Query(rson,val);
    PushUP(rt);
    return ret;
}
void Change(int x,int y,int val,int st)
{
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        Update(p[top[x]],p[x],val,1,n,1,st);
        x=fa[top[x]];
    }
    if(deep[x]>deep[y]) swap(x,y);
    Update(p[x],p[y],val,1,n,1,st);
}

int main()
{
    char oper[10];
	int t; 
	scanf("%d",&t);
    int a,b,c;
	for(int ca = 1 ; ca <= t; ca ++)
    {
		scanf("%d%d",&n,&Q);
        Init();
        for(int i=1;i<=n-1;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        dfs1(1,0,0);
        dfs2(1,1);
		Build(1,n,1);
        while(Q--)
        {
            scanf("%s",oper);
            if(oper[3]=='2')
            {
                scanf("%d%d%d",&a,&b,&c);
                Change(a,b,c,0);
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                Change(a,b,c,1);
            }
        }
		printf("Case #%d:\n",ca);
		for(int i = 1;i <= n;i ++)
          printf(i == 1?"%d":" %d",Query(1,n,1,p[i]));
		printf("\n");
		for(int i = 1;i <= n-1 ;i ++)
          printf(i == 1?"%d":" %d",ans[p[i]]);
		printf("\n");
    }
    return 0;
}

