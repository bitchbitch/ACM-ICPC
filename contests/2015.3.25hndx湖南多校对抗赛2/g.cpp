// File Name: f.cpp
// Author: darkdream
// Created Time: 2015年03月25日 星期三 13时46分59秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long
#define maxn 310005
using namespace std;
char str[maxn];
struct nodd{
  int l , r , m ,mi,lazy;
}tree[maxn*4];
int sum[maxn];
int L(int x)
{
  return 2 *x; 
}
int R(int x)
{
  return 2*x + 1; 
}
void push_up(int c)
{
   tree[c].mi = min(tree[L(c)].mi ,tree[R(c)].mi);
}
void push_down(int c)
{
  if(tree[c].lazy != 0 )
  {
   tree[L(c)].mi += tree[c].lazy ; 
   tree[R(c)].mi += tree[c].lazy;
   tree[L(c)].lazy += tree[c].lazy;
   tree[R(c)].lazy += tree[c].lazy ; 
   tree[c].lazy = 0 ; 
  }
}
void build(int c, int l ,int  r)
{
   tree[c].l = l ; 
   tree[c].r = r; 
   tree[c].m = (l+r)/2;
   tree[c].lazy = 0 ; 
   if(l == r)
   {
	   //printf("**%d\n",sum[l]);
	   tree[c].mi = sum[l];
	   return ;
   }
   build(L(c),l,tree[c].m);
   build(R(c),tree[c].m +1, r);
   push_up(c);
}
void update(int c, int l , int r ,int v)
{
   if(l <= tree[c].l && r >= tree[c].r)
   {
      tree[c].mi += v; 
	  tree[c].lazy += v ;
	  return ;
   }
   push_down(c);
   if(l <= tree[c].m)
	   update(L(c),l,r,v);
   if(r > tree[c].m)
	   update(R(c),l,r,v);
   push_up(c);
}
int find(int c, int p )
{
    //printf("%d %d %d \n",c,tree[c].l,tree[c].r); 
	if(tree[c].l == tree[c].r )
	 {
		if(tree[c].mi >= 2)
	       return tree[c].l; 
		return 1e9; 
	 }
	 push_down(c);
	 if(p <= tree[c].m && p >= tree[c].l)
	 {
	    return find(L(c),p);
	 }
	 int t ;
	 //if(tree[c].l == 1)
	//	 printf("***%d\n",tree[R(c)].mi);
	 if(tree[R(c)].mi >= 2)
		 t = tree[c].m + 1;
	 else 
	     t = find(R(c),p);
	 if(t == tree[c].m + 1)
	 {
	     if(tree[L(c)].mi >= 2 ) 
			 return tree[c].l;
		 t = min(t,find(L(c),p));
	//	 printf("***%d %d\n",t,);
	 }else{
	   return t;
	 }
}
set<int> st;
int main(){
    int n , m;
    scanf("%d %d",&n,&m);
    scanf("%s",&str[1]);
	for(int i = 1;i <= n;i ++)
	{
		
        if(str[i] == ')')	
		{
		  st.insert(i);
		  sum[i] = sum[i-1] - 1;
		}else{
		  sum[i] = sum[i-1] + 1;
		}
	}
	build(1,1,n);
	int q; 
    for(int i = 1;i <= m;i ++)
	{
	   scanf("%d",&q);
       if(str[q] == '(')  
	   {
	        str[q] = ')';	
			update(1,q,n,-2);
			st.insert(q);
			int t = *st.begin();
			printf("%d\n",t);
			st.erase(st.find(t));
		    update(1,t,n,2);
			str[t] = '(';
	   }else{
	        str[q] = '(';
			st.erase(st.find(q));
			update(1,q,n,2);    
			int t = find(1,q);
			update(1,t,n,-2);
			str[t] = ')';
			st.insert(t);
			printf("%d\n",t);
	   }
	   //puts(&str[1]);
	}
return 0;
}
