#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define N 400020
struct seg
{
    int x1,x2,y;
    int mark;
    seg(){}
    seg(int a,int b,int c,int d):x1(a),x2(b),y(c),mark(d){}
    bool operator < (const seg & a)const{return y<a.y;}
};
struct node{
    int l,r,len,len2;
    int cov;
    node *left,*right;
    node(int a,int b)
    {
        l=a;r=b;len=len2=0;cov=0;
        left=right=NULL;
    }
};
int xis[N*2];
seg s[N*2];
node *build(int s,int t){
    node * root=new node(xis[s],xis[t]);
    if(t>s+1)
    {
        int m=(s+t)>>1;
        root->left= build(s,m);
        root->right=build(m,t);
    }
    return root;
}
void update(node *root)
{
    root->len=0;
    if(root->cov >0)
        root->len=root->r - root->l;
    else
    {
        if(root->left) root->len += root->left->len;
        if(root->right) root->len += root->right->len;
    }
}
void insert(node *root,seg line)
{
    if(root->l == line.x1 &&root->r == line.x2)
        root->cov +=line.mark;
    else if(root->left->r >= line.x2)
        insert(root->left,line);
    else if(root->right->l <= line.x1)
        insert(root->right,line);
    else
    {
        seg f=line;
        f.x2=root->left->r;
        insert(root->left,f);
        f=line; f.x1=root->left->r;
        insert(root->right,f);
    }
    update(root);
}
void bbt(int &cnt,int &flag,int x1,int y1,int x2,int y2){
    if(x1==x2 || y1==y2) return; //去掉退化矩形
    xis[cnt++]=x1;xis[cnt++]=x2;
    s[flag++]=seg(x1,x2,y1,1);
    s[flag++]=seg(x1,x2,y2,-1);
}
struct sg
{
    int x1,y1,x2,y2;
    sg(){}
    sg(int a,int b,int c,int d)
    {x1=a;y1=b;x2=c;y2=d;}
};
int read(int &n,sg *in)
{
    int cnt=0,flag=0;
    for(int i=0;i<n;++i)
        bbt(cnt,flag,in[i].x1,in[i].y1,in[i].x2,in[i].y2);
    sort(xis,xis+cnt);
    sort(s,s+flag);
    n=unique(xis,xis+cnt)-xis; //去重
    return flag;
}
long long work(sg *in,int &n)
{
    int cnt=read(n,in);
    node *root= build(0,n-1);
    long long sum=0ll;
    for(int i=0;i<cnt-1;++i)
    {
        insert(root,s[i]);
        sum+= (root->len) *1ll *(s[i+1].y - s[i].y);
    }
    return sum;
}
sg box[N];
int main()
{
    int i,n,m;
    int x1,y1,x2,y2,x3,y3,x4,y4;
    while(scanf("%d",&n)&&n)
    {
        m=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
            box[m++]=sg(x1,y1,x2,y3);
            box[m++]=sg(x1,y4,x2,y2);
            box[m++]=sg(x1,y3,x3,y4);
            box[m++]=sg(x4,y3,x2,y4);
        }
        cout<<work(box,m)<<endl;
    }
    return 0;
}
