#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define maxn 100005
char cstr[maxn];
int L(int x)
{
  return 2*x;
}
int R(int x)
{
  return 2*x +1;
}
struct node
{
  int vx,vy,vz;
  int l,r,m;
}tree[maxn];
void update(int c)
{
  tree[c].vx  = tree[L(c)].vx + tree[R(c)].vx;
  tree[c].vy = tree[L(c)].vy + tree[R(c)].vy;
  tree[c].vz = tree[L(c)].vz + tree[R(c)].vz;
}
void maketree(int c, int p,int v )
{
    tree[c].l = p ; 
	tree[c].r = v; 
	tree[c].m = (p+v)/2;
	if(p== v)
	{
	  tree[c].vx = 0 ; 
	  tree[c].vy = 0 ; 
	  tree[c].vz = 0 ;
	  if(cstr[p - 1] == 'x')
	  {
	    tree[c].vx ++;
	  }else if(cstr[p - 1] == 'y')
	  {
	    tree[c].vy ++;
	  }else if(cstr[p - 1] == 'z')
	  {
	    tree[c].vz ++;
	  }
	  return;
	}
    maketree(L(c),p,tree[c].m);
	maketree(R(c),tree[c].m+1,v);
    update(c);
}
int tvx = 0; 
int tvy = 0 ; 
int tvz = 0 ;
void find(int c,int p , int v)
{
  printf("%d\n",c);
  if(p <= tree[c].l && v >= tree[c].r)
  {
    tvx += tree[c].vx;
    tvy += tree[c].vy;
    tvz += tree[c].vz;
	return;
  }
  if(v <= tree[c].m)
  {
    find(L(c),p,v);
  }else if(p > tree[c].m)
  {
    find(R(c),p,v);
  }else {
    find(L(c),p,tree[c].m);
	find(R(c),tree[c].m+1,v);
  }
}
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
  scanf("%s",cstr);
  maketree(1,1,strlen(cstr));
  int m ; 
  scanf("%d",&m);
  while(m--)
  {
    int a,b; 
	scanf("%d %d",&a,&b);
	tvx = 0;
	tvy = 0; 
	tvz = 0;
	find(1,a,b);
    if(tvz && tvy && tvx)
	  printf("NO\n");
	else printf("YES\n");
  }

return 0;
}
