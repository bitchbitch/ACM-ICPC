#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500000+100;
const int INF=0x3f3f3f3f;
#define Key_Value ch[ch[root][1]][0]
int pre[maxn],ch[maxn][2],size[maxn],key[maxn],root,tot1;
int sum[maxn],rev[maxn],setv[maxn],lx[maxn],rx[maxn],mx[maxn];
int s[maxn],tot2;
int n,q;
int a[maxn];
void New_Node(int &r,int fa,int k)
{
    if(tot2) r=s[tot2--];
    else r=++tot1;
    key[r]=k;
    pre[r]=fa;
    rev[r]=setv[r]=ch[r][0]=ch[r][1]=0;
    size[r]=1;
    sum[r]=lx[r]=rx[r]=mx[r]=k;
}
void Update_Rev(int r)
{
    if(!r) return ;
    swap(ch[r][0],ch[r][1]);
    swap(lx[r],rx[r]);
    rev[r]^=1;
}
void Update_Set(int r,int val)
{
    if(!r) return;
    setv[r]=1;//注意
    key[r]=val;
    sum[r]=size[r]*val;
    lx[r]=rx[r]=mx[r]=max(val,val*size[r]);
}
void Push_Up(int r)
{
    int lson=ch[r][0],rson=ch[r][1];
    size[r]=1+size[lson]+size[rson];
    sum[r]=key[r]+sum[lson]+sum[rson];
    lx[r]=max(lx[lson],sum[lson]+key[r]+max(0,lx[rson]));
    rx[r]=max(rx[rson],sum[rson]+key[r]+max(0,rx[lson]));
    mx[r]=max(0,rx[lson])+key[r]+max(0,lx[rson]);
    mx[r]=max(mx[r],max(mx[lson],mx[rson]));
}
void Push_Down(int r)
{
    if(setv[r])
    {
        Update_Set(ch[r][0],key[r]);
        Update_Set(ch[r][1],key[r]);
        setv[r]=0;
    }
    if(rev[r])
    {
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r]=0;
    }
}
void Build(int &x,int l,int r,int fa)
{
    if(l>r)return;
    int mid=(l+r)>>1;
    New_Node(x,fa,a[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
void Init()
{
    root=tot1=tot2=0;
    pre[root]=ch[root][0]=ch[root][1]=size[root]=sum[root]=rev[root]=setv[root]=key[root]=0;
    lx[root]=rx[root]=mx[root]=-INF;
    New_Node(root,0,-1);
    New_Node(ch[root][1],root,-1);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    Build(Key_Value,0,n-1,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Rotate(int x,int kind)
{
    int y=pre[x];
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y]) ch[pre[y]][ch[pre[y]][1]==y] = x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    Push_Up(y);
}
void Splay(int r,int goal)
{
    while(pre[r]!=goal)
    {
        if(pre[pre[r]]==goal)
            Rotate(r,ch[pre[r]][0]==r);
        else
        {
            int y=pre[r];
            int kind=ch[pre[y]][0]==y;
            if(ch[y][kind]==r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    Push_Up(r);
    if(goal==0) root=r;
}
int Get_Kth(int r,int k)
{
    Push_Down(r);
    int t=size[ch[r][0]]+1;
    if(k==t) return r;
    else if(k<t) return Get_Kth(ch[r][0],k);
    else return Get_Kth(ch[r][1],k-t);
}
void Insert(int pos,int tot)
{
    for(int i=0;i<tot;i++) scanf("%d",&a[i]);
    Splay(Get_Kth(root,pos+1),0);
    Splay(Get_Kth(root,pos+2),root);
    Build(Key_Value,0,tot-1,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void erase(int r)
{
    if(!r) return;
    s[++tot2]=r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}
void Delete(int pos,int tot)
{
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    erase(Key_Value);
    pre[Key_Value]=0;
    Key_Value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Set(int pos,int tot,int c)
{
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    Update_Set(Key_Value,c);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Reverse(int pos,int tot)
{
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    Update_Rev(Key_Value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int Get_Sum(int pos,int tot)
{
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    return sum[Key_Value];
}
int Get_MaxSum(int pos,int tot)
{
    Splay(Get_Kth(root,pos),0);
    Splay(Get_Kth(root,pos+tot+1),root);
    return mx[Key_Value];
}
int main()
{
	freopen("in","r",stdin);
	freopen("output1","w",stdout);
    while(scanf("%d%d",&n,&q)==2)
    {
        Init();
        char op[20];
        int x,y,z;
        while(q--)
        {
            scanf("%s",op);
            if(op[0]=='I')
            {
                scanf("%d%d",&x,&y);
                Insert(x,y);
            }
            else if(op[0]=='D')
            {
                scanf("%d%d",&x,&y);
                Delete(x,y);
            }
            else if(op[0]=='M'&&op[2]=='K')
            {
                scanf("%d%d%d",&x,&y,&z);
                Set(x,y,z);
            }
            else if(op[0]=='R')
            {
                scanf("%d%d",&x,&y);
                Reverse(x,y);
            }
            else if(op[0]=='G')
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",Get_Sum(x,y));
            }
            else
            {
                printf("%d\n",Get_MaxSum(1,size[root]-2));
            }
        }
    }
    return 0;
}



















