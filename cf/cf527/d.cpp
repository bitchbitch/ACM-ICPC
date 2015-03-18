// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年03月18日 星期三 15时28分50秒

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
#define maxn 700000
int lowbit(int x)
{
   return x &(-x);
}
int tree[maxn];
int getsum(int x)
{
	int sum = 0;
	while(x >= 1)
	{
	    sum = max(tree[x],sum);
		x -= lowbit(x);
	}
	return sum; 
}
int n,m,tt; 
void update(int k ,int v)
{
    while(k <= tt) 
	{
	  tree[k] =  max(tree[k],v); 
	  k += lowbit(k);
	}
}
struct node{
    int x ,l , r; 
}qu[maxn];
int cmp(int x, int y)
{
  return x < y ; 
}
int nodecmp(node x, node y)
{
    return x.x < y.x; 
}
map<int ,int > mp;
int ch[maxn];
int main(){
	 m = 0 ; 
	 scanf("%d",&n);
     int tm;
	 for(int i = 1;i <= n;i ++)
	 {
		scanf("%d %d",&qu[i].x,&tm);
		qu[i].l = qu[i].x - tm;
		qu[i].r = qu[i].x + tm;
		ch[m+1] = qu[i].l; 
		ch[m+2] = qu[i].r;
		m += 2; 
	 }
	 sort(qu+1,qu+1+n,nodecmp);
	 sort(ch+1,ch+1+m,cmp);
	 ch[0] = -1e9- 1000;
	 tt = 0 ; 
	 for(int i =1 ;i <= m;i ++)
	 {
	     if(ch[i] != ch[i-1]) 
		 {
		   tt ++ ;
		   mp[ch[i]]  = tt; 
		 }
	 }
	 int ans = 0 ;
	 for(int i = 1;i <= n;i ++)
	 {
	    int l = mp[qu[i].l];
	    ans = getsum(l); 
		//printf("%d %d %I64d\n",l,mp[qu[i].r],getsum(l));
		update(mp[qu[i].r],ans +1);
	 }
	 ans = getsum(tt);
     printf("%d\n",ans); 
return 0;
}
