#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 200005
struct node
{
    long long left ,right,mid;
	long long  num ;
    long long cover;
} tree[MAXN*4];
long long a[MAXN];
long long L(long long c)
{
    return 2*c;
}
long long R(long long c)
{
    return 2*c + 1;
}
void up(long long c)
{
    tree[c].num = tree[L(c)].num + tree[R(c)].num;
}
void build(long long c, long long p ,long long v )
{
   tree[c].left = p ; 
   tree[c].right = v; 
   tree[c].mid = (p + v)/2;
   tree[c].num =0 ; 
   tree[c].cover = 0 ; 
   if(p == v )
   {
	 tree[c].num = a[p];
     return ; 
   }
  build(L(c),p,tree[c].mid);
  build(R(c),tree[c].mid +1,v);
  up(c);
}

void update(long long c, long long p , long long v , long long value)
{
    if(p <= tree[c].left && v >= tree[c].right)
	{
	    tree[c].num += (tree[c].right - tree[c].left +1) * value;
		tree[c].cover += value ;
		return; 
	}
   if(tree[c].cover != 0 )
   {
      tree[L(c)].cover = tree[c].cover;
	  tree[L(c)].num += (tree[L(c)].right - tree[L(c)].left +1) * tree[L(c)].cover;
	  tree[R(c)].cover = tree[c].cover;
	  tree[R(c)].num += (tree[R(c)].right - tree[R(c)].left + 1)* tree[R(c)].cover ; 
	  tree[c].cover  = 0 ; 
   }
   if(v <= tree[c].mid )  update(L(c),p,v,value);
   else if(p > tree[c].mid) update(R(c),p,v,value);
   else
   {
     update(L(c),p,tree[c].mid,value);
	 update(R(c),tree[c].mid+ 1, v , value);
   }
   // there or getsum have some wrong    
   up(c);	
}  

long long  tsum = 0 ;
void getsum(long long c, long long p ,long long v )
{
    if(p <= tree[c].left && v >= tree[c].right)
	{
		tsum += tree[c].num;
		return; 
	}
   if(tree[c].cover != 0 )
   {
      tree[L(c)].cover = tree[c].cover;
	  tree[L(c)].num += (tree[L(c)].right - tree[L(c)].left +1) * tree[L(c)].cover;
	  tree[R(c)].cover = tree[c].cover;
	  tree[R(c)].num += (tree[R(c)].right - tree[R(c)].left + 1)* tree[R(c)].cover ; 
	  tree[c].cover  = 0 ; 
   }
   if(v <= tree[c].mid) getsum(L(c),p,v);
   else if(p > tree[c].mid) getsum(R(c),p,v);
   else 
   {
     getsum(L(c),p,tree[c].mid);
	 getsum(R(c),tree[c].mid +1 ,v );
   }

}
int main()
{
    long long  n ,m;
    while(scanf("%lld %lld",&n,&m) != EOF)
    {

      for (long long i = 1;i <= n;i ++)
        scanf("%lld",&a[i]);
      build(1,1,n);
      char str[10];
      for(long long i =1 ;i <= m;i ++)
      {
          long long a, b ,c;
          scanf("%s",str);
          if(str[0] == 'Q')
          {
            scanf("%lld %lld",&a,&b);
            if(a >b )
            {
              long long  temp = a ;
              a = b ;
              b = temp ;
            }
            tsum = 0 ;
            getsum(1,a,b);
            printf("%lld\n",tsum);
          }
          else
          {
            scanf("%lld %lld %lld",&a,&b,&c);
            if(a > b )
            {
             long long temp = a;
             a = b;
             b = temp;
            }
            update(1,a,b,c);
          }

      }
    }
    return  0 ;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
4
C 3 6 3
Q 1 5
24
Q 6 10
43
Q 1 10
67
C  1 1 1              
Q 1 5
16
*/
