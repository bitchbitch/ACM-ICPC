#include<cstdio>
#include<iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int mm=111111;
int dly[mm<<2],rev[mm<<2],sum[mm<<2],lmax[mm<<2],lmin[mm<<2];
char str[mm];
void reverse(int rt)
{
    sum[rt]=-sum[rt];
    int tmp=lmax[rt];
    lmax[rt]=-lmin[rt];
    lmin[rt]=-tmp;
    rev[rt]^=1;
}
void set(int rt,int op,int len)
{
    sum[rt]=op*len;
    lmax[rt]=sum[rt]>0?sum[rt]:0;
    lmin[rt]=sum[rt]<0?sum[rt]:0;
    dly[rt]=op,rev[rt]=0;
}
int pushdown(int rt,int l1,int l2)
{
    if(rev[rt])
    {
        if(dly[rt])dly[rt]=-dly[rt];
        else reverse(rt<<1),reverse(rt<<1|1);
        rev[rt]=0;
    }
    if(dly[rt])
    {
        set(rt<<1,dly[rt],l1),set(rt<<1|1,dly[rt],l2);
        dly[rt]=0;
    }
}
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    lmax[rt]=max(lmax[rt<<1],sum[rt<<1]+lmax[rt<<1|1]);
    lmin[rt]=min(lmin[rt<<1],sum[rt<<1]+lmin[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    dly[rt]=rev[rt]=0;
    if(l==r)
    {
        sum[rt]=(str[l]=='(')?-1:1;
        lmax[rt]=(sum[rt]<0)?0:1;
        lmin[rt]=(sum[rt]<0)?-1:0;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void updata(int L,int R,int op,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        if(op)set(rt,op,r-l+1);
        else reverse(rt);
        return;
    }
    int m=(l+r)>>1;
    pushdown(rt,m-l+1,r-m);
    if(L<=m)updata(L,R,op,lson);
    if(R>m)updata(L,R,op,rson);
    pushup(rt);
}
int querys(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)return sum[rt];
    int m=(l+r)>>1,ret=0;
    pushdown(rt,m-l+1,r-m);
    if(L<=m)ret+=querys(L,R,lson);
    if(R>m)ret+=querys(L,R,rson);
    pushup(rt);
    return ret;
}
int querym(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)return lmax[rt];
    int m=(l+r)>>1,ret;
    pushdown(rt,m-l+1,r-m);
    if(R<=m)ret=querym(L,R,lson);
    else if(L>m)ret=querym(L,R,rson);
    else ret=max(querym(L,R,lson),querys(L,R,lson)+querym(L,R,rson));
    pushup(rt);
    return ret;
}
int main()
{
    int i,j,n,m,t,cs;
    char op[55];
	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output1.txt","w",stdout);
	scanf("%d",&t);
    for(cs=1;cs<=t;++cs)
    {
        printf("Case %d:\n",cs);
        scanf("%d%s%d",&n,str,&m);
        build(0,n-1,1);
        while(m--)
        {
            scanf("%s%d%d",op,&i,&j);
            if(op[0]=='s')
            {
                scanf("%s",op);
                updata(i,j,op[0]=='('?-1:1,0,n-1,1);
            }
            else if(op[0]=='r')updata(i,j,0,0,n-1,1);
            else if(!querys(i,j,0,n-1,1)&&!querym(i,j,0,n-1,1))puts("YES");
            else puts("NO");
        }
        printf("\n");
    }
    return 0;
}

