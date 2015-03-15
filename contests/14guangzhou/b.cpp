#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=1000110;

#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)

struct Tree{
    int l,r;
    int col;   
    bool cover; 
}tree[N<<2];

void PushUp(int rt){    
    tree[rt].col=tree[L(rt)].col | tree[R(rt)].col;
}

void build(int L,int R,int rt){
    tree[rt].l=L;
    tree[rt].r=R;
    tree[rt].col=2; 
    tree[rt].cover=1;
    if(tree[rt].l==tree[rt].r)
        return ;
    int mid=(L+R)>>1;
    build(L,mid,L(rt));
    build(mid+1,R,R(rt));
}

inline void PushDown(int rt){  
    tree[L(rt)].col=tree[rt].col;
    tree[L(rt)].cover=1;
    tree[R(rt)].col=tree[rt].col;
    tree[R(rt)].cover=1;
    tree[rt].cover=0;
}
void update(int val,int L,int R,int rt){
    if(L<=tree[rt].l && R>=tree[rt].r){
        tree[rt].col=val;
        tree[rt].cover=1;
        return ;
    }
    if(tree[rt].col==val)  
        return ;
    if(tree[rt].cover)
        PushDown(rt);
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(R<=mid)
        update(val,L,R,L(rt));
    else if(L>=mid+1)
        update(val,L,R,R(rt));
    else{
        update(val,L,mid,L(rt));
        update(val,mid+1,R,R(rt));
    }
    PushUp(rt);
}

int sum;

inline void query(int L,int R,int rt){
    if(L<=tree[rt].l && R>=tree[rt].r){
        sum |= tree[rt].col;
        return ;
    }
    if(tree[rt].cover){  
        sum |= tree[rt].col;
        return;
    }
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(R<=mid)
        query(L,R,L(rt));
    else if(L>=mid+1)
        query(L,R,R(rt));
    else{
        query(L,mid,L(rt));
        query(mid+1,R,R(rt));
    }
}

inline void solve(){
    int tt  = 0; 
	int p = 0 ; 
	while(sum){
		tt ++ ;
        if(sum&1)
		{
			if(p == 0 )
			{
			 printf("%d",tt);
			 p ++ ;
			}
			else printf(" %d",tt);
		}
        sum>>=1;
    }
	printf("\n");
}

void swap(int &a,int &b){
    int tmp=a;a=b;b=tmp;
}

int main(){


    int n,t,m;
    while(~scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0 )
		   break;
		build(1,n,1);
        char op[3];
        int a,b,c;
        while(m--){
            scanf("%s",op);
            if(op[0]=='P'){
                scanf("%d%d%d",&a,&b,&c);
                if(a>b)
                    swap(a,b);
                update(1<<(c-1),a,b,1);
            }else{
                scanf("%d%d",&a,&b);
                if(a>b)
                    swap(a,b);
                sum=0;
                query(a,b,1);
                solve();
			}
        }
    }
    return 0;
}
