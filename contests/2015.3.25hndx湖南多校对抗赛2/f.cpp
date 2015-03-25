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
#define maxn 300005
using namespace std;
char str[maxn];
struct nodd{
  int l , r , m ,sum;
}tree[maxn];
int L(int x)
{
  return 2 *x; 
}
int R(int x)
{
  return 2*x + 1; 
}
void insert_up(int c)
{
  tree[c].sum = tree[L(c)].sum + tree[R(c)].sum;
}
void build(int c, int l ,int  r)
{
   tree[c].l = l ; 
   tree[c].r = r; 
   tree[c].m = (l+r)/2;
   if(l == r)
   {
     if(str[l] == ')')
		 tree[c].sum  = -1;
	 else tree[c].sum = 1;
	 return ;
   }
   build(L(c),l,tree[c].m);
   build(R(c),tree[c].m +1, r);
   insert_up(c);
}
void update(int c,int p)
{
    if(tree[c].l == tree[c].r)
	{
	  tree[c].sum = -tree[c].sum;
	  return;
	}
	if(p <= tree[c].m)
		update(L(c),p);
	else update(R(c),p);
	insert_up(c);
}
int ans = 0 ;
void find(int c ,int lsum,int p)
{
     if(tree[c].l == tree[c].r)
	 {
	    ans = tree[c].l;
		return;
	 }
	 if(p <= tree[c].m || ){
	 
	 }else{
	 
	 }
}
set<int> st;
int main(){
    int n , m;
    scanf("%d %d",&n,&m);
    scanf("%s",&str[1]);
	build(1,1,n);
	for(int i = 1;i <= n;i ++)
	{
        if(str[i] == ')')	
		  st.insert(i);
	}
	int q; 
    for(int i = 1;i <= m;i ++)
	{
	   scanf("%d",&q);
       if(str[q] == '(')  
	   {
	        str[q] = ')';
			update(1,q);
			st.insert(q);
			int t = *st.begin();
			printf("%d\n",t);
			st.erase(st.begin());
		    update(1,t);
			str[t] = '(';
	   }else{
	        str[q] = '(';
			st.erase(st.find(q));
			update(1,q);

			find(1,2,q);
			update(1,ans);
			str[ans] = ')';
			st.insert(ans);
			printf("%d\n",ans);
	   }
	}
return 0;
}
