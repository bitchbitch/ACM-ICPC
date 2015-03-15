// File Name: poj2182.c
// Author: darkdream
// Created Time: 2013年07月29日 星期一 22时05分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#define MAXN 200005
struct node
{
  int left ,right ,mid ; 
  int num;  
}tree[MAXN* 4];
int a[MAXN];
int R(int c)
{
  return 2 * c+1; 
}
int L(int c)
{
  return 2 * c; 
}
void up(int c)
{ 
	tree[c].num = tree[L(c)].num + tree[R(c)].num ;
}
void build(int c, int p ,int v)
{
   tree[c].left = p;
   tree[c].right = v ;
   tree[c].mid = (p + v )/2;
   tree[c].num = v-p + 1 ; 
   if(p == v )
   {
    return; 
   }
   build(L(c),p,tree[c].mid);
   build(R(c),tree[c].mid + 1, v);
}
int ok= 0 ;
void update( int c, int p )
{
	tree[c].num --;
	if(tree[c].left == tree[c].right)
	{
	 ok = tree[c].left;
	 return;
	}
    if(p >  tree[L(c)].num) update(R(c),p - tree[L(c)].num);
	else update(L(c),p);
}
int tsum  = 0 ; 
void getsum (int c, int p , int v )
{
    if(p <= tree[c].left && v >= tree[c].right)
	{
	 tsum += tree[c].num;
	 return ; 
	}
   if(v <= tree[c].mid) getsum(L(c),p,v);
   else if(p > tree[c].mid) getsum(R(c),p,v);
   else 
   {
      getsum(L(c),p,tree[c].mid);
	  getsum(R(c),tree[c].mid+1,v);
   }
}
int b[MAXN];
int c[MAXN];
int main(){


   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n; 
   while(scanf("%d",&n) != EOF)
   {
	for(int i = 1;i <= n;  i ++)
	 {
		 scanf("%d %d",&a[i],&c[i]);
	     a[i] = a[i] + 1; 
	 }
	 b[a[n]] = c[n];
	 build(1,1,n);
	 update(1,a[n]);
	 for(int i= n -1; i >= 1; i -- )
	 {
	    ok = 0; 	
	    //printf("%d\n",tsum);
		update(1,a[i]);
		b[ok] = c[i];
	 }
	 for(int i = 1;i <= n;i ++)
		 printf("%d ",b[i]);
     printf("\n");
   }
return 0 ;
}

