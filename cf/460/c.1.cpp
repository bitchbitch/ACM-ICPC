#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100005
#define LL long long 
int a[100005];
int L(int  c)
{
  return c * 2;
}
int R(int c)
{
   return c * 2 + 1;
}

struct node
{
   int l , r ,m;
   int x;
   LL mi ;
}tree[MAX * 4];
void up(int c)
{
   tree[c].mi = min(tree[L(c)].mi + tree[R(c)].mi)
}
void down(int c)
{
}
void build(int c, int p , int v )
{
    tree[c].l = p ;
    tree[c].r = v;
    tree[c].m = (p + v )/2;
    tree[c].sum = 0 ;
    tree[c].x = 0 ; 
    if(p == v )
    {
        return ;
    }
    build(L(c),tree[c].l,tree[c].m);
    build(R(c),tree[c].m+1,v);
}
void update(int c, int l , int r,int x)
{
    if(l <= tree[c].l && r >= tree[c].r)
    {
       tree[c].sum += 1ll*(tree[c].r-tree[c].l+1) *x;
       tree[c].x += x;
       return; 
    }
    down(c);
    if(l <= tree[c].m) 
        update(L(c),l,r,x);
    if(r > tree[c].m)
        update(R(c),l,r,x);
    up(c);
}
LL ans = 0 ; 
void getsum (int c, int l , int r)
{
    if(l <= tree[c].l && r >= tree[c].r)
    {
      ans += tree[c].sum;
      return ;
    }
    down(c);
    if(l <= tree[c].m) 
        getsum(L(c),l,r);
    if(r > tree[c].m)
        getsum(R(c),l,r);

}
int main()
{
    int n , m , w;
	scanf("%d %d %d",&n,&m,&w);
	
	return 0 ;
}
