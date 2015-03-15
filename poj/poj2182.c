// File Name: poj2182.c
// Author: darkdream
// Created Time: 2013年07月29日 星期一 22时05分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#define MAXN 8005
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
   tree[c].num = 1 ; 
   if(p == v )
   {
    return; 
   }
   build(L(c),p,tree[c].mid);
   build(R(c),tree[c].mid + 1, v);
}
void update( int c, int p )
{
    if(tree[c].left  ==  p && tree[c].right == p )
	{
	   tree[c].num  = 0 ; 
	   return; 
	}
    if(p <= tree[c].mid) update(L(c),p);
	else update(R(c),p);
	up(c);
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
int main(){


   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n; 
   while(scanf("%d",&n) != EOF)
   {
	memset(b,0,sizeof(b));
     a[1] = 0 ; 
     for(int i = 2;i <= n;  i ++)
		 scanf("%d",&a[i]);
	 b[n] = a[n]+1;
	 build(1,1,n+1);
	 update(1,b[n]);
	 for(int i= n -1; i >= 1; i -- )
	 {
	   int low = 1, high = n;
	    while(low <= high)
		{
		  int mid = (low + high )/2;
		  tsum = 0 ; 
		  getsum(1,1,mid);
		  if(tsum > a[i])
		   low = mid + 1; 
		  else  high = mid - 1; 
		}
		b[i] = high;
		printf("%d\n",b[i]);
		update(1,b[i]);
	 }
	 for(int i = 1;i <= n;i ++)
		 printf("%d ",b[i] + 1);


   }
return 0 ;
}
