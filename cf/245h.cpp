// File Name: 245h.cpp
// Author: darkdream
// Created Time: 2015年03月30日 星期一 11时09分19秒

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

using namespace std;
char  str[6000];
map<int ,int >dpj[5005];
map<int ,int >dpo[5005];
map<int ,int >::iterator tp;
struct qu{
 int l , r,si; 
}a[1000005];
int ans[1000005];
int q, n ; 
int cmp(qu a, qu b)
{
  return a.l > b.l ;
}
struct node{
   int l , r, m , v ; 
}tree[6005*4];
int L(int c)
{
 return 2* c; 
}
int R(int c)
{
  return 2 * c + 1; 
}
void push_up(int c)
{
  tree[c].v = tree[L(c)].v + tree[R(c)].v; 
}
void build(int c, int l, int r)
{
   tree[c].l = l ; 
   tree[c].r = r; 
   tree[c].m = (l + r)/2;
   if(tree[c].l == tree[c].r)
   {
     tree[c].v = 1; 
	 return ;
   }
   build(L(c),l,tree[c].m);
   build(R(c),tree[c].m + 1, r );
   push_up(c);
}
void update(int c ,int p )
{
    if(tree[c].l == tree[c].r)
	{
	   tree[c].v +=1 ; 
	   return ;
	}
	if(p <= tree[c].m)
		update(L(c),p);
	else update(R(c),p);
	push_up(c);
}
int tsum = 0 ; 
void find(int c, int l , int r)
{
    if(l <= tree[c].l && tree[c].r <=  r)
    {
	  tsum += tree[c].v ;
	  return ; 
	}
	if(l <= tree[c].m)
		find(L(c),l,r);
	if(r > tree[c].m)
		find(R(c),l,r);
}
inline void read_int(int &ret){
   char ch = getchar();
   while(!isdigit(ch)){
     ch = getchar();
   }
   ret =0 ; 
   while(isdigit(ch)){
      ret = ret*10 + ch -'0' ;
	  ch = getchar();
   }
}
int main(){
    freopen("input","r",stdin);
	freopen("output","w",stdout);
	clock_t be ,en ;
	be = clock();
	scanf("%s",&str[1]);
	 scanf("%d",&q);
	 for(int i = 1;i <=q ;i ++)
	 {
		 read_int(a[i].l);
		 read_int(a[i].r);
		 a[i].si = i ; 
	 }
	 sort(a+1,a+1+q,cmp);
     int n = strlen(&str[1]);
	 build(1,1,n);
	 int tt = 1;  
	 for(int i = n;i >= 1;i --)
	 {
	    dpj[i][1] = i;
		if(str[i] == str[i+1])
		{
		  dpo[i][2] = i+1;
		  update(1,i+1);
		}
        for(tp = dpj[i+1].begin() ; tp != dpj[i+1].end();tp++)
		{
		   if(str[i] == str[tp->second +1])
		   {
		       dpj[i][tp->first+2] = tp->second +1;
			   update(1,tp->second+1);
		   }
		}
        for(tp = dpo[i+1].begin() ; tp != dpo[i+1].end();tp++)
		{
		   if(str[i] == str[tp->second +1])
		   {
		       dpo[i][tp->first+2] = tp->second +1;
			   update(1,tp->second+1);
		   }
		}
		while(a[tt].l == i && tt <= q)
		{
		   tsum = 0 ; 
		   find(1,a[tt].l ,a[tt].r);
		   ans[a[tt].si] = tsum; 
		   tt++;
		}
		if(tt >q)
			break;
		dpj[i+1].clear();
		dpo[i+1].clear();
	 }
	 for(int i = 1;i <= q; i ++)
		 printf("%d\n",ans[i]);
	 en = clock();
	 printf("%lf\n",(en -be)*1.0/CLOCKS_PER_SEC);
return 0;
}
