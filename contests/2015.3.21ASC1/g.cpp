// File Name: g.cpp
// Author: darkdream
// Created Time: 2015年03月21日 星期六 16时59分08秒

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
int n ;
struct node{
  int s, b,si; 
}a[100005];
int cmp(node a, node b)
{
   if(a.s == b.s)
	   return a.b > b.b; 
   return a.s < b.s;
}
int dp[100005];
int si[100005];
int last[100005];
int top = 0 ;
int findsite(int v,int r)
{
  int l = 1;
  while(l <= r)
  {
     int mid = (l +r) >>1;
	 if(dp[mid] < v)
	 {
	     l = mid + 1;
	 }else{
	     r = mid -1;  
	 }
  }
  return l ; 
}
void solve()
{
	dp[1] = a[1].b ; 
	top = 1; 
	si[1] = a[1].si;
	last[1] = 0 ; 
    for(int i = 2;i <= n;i ++)
	{
        if(a[i].b > dp[top])
		{
		  top ++ ; 
		  dp[top] = a[i].b;
		  si[top] = a[i].si ; 
		  last[a[i].si] = si[top-1];
		  continue;
		}
		int k = findsite(a[i].b,top);
		if(a[i].b == dp[k])
			continue;
		dp[k] = a[i].b ; 
		si[k] = a[i].si ; 
		last[a[i].si] = si[k-1];
		/*for(int j = 1;j <= top;j ++)
			printf("%d ",dp[j]);
		printf("\n");
		for(int j = 1;j <= top;j ++)
			printf("%d ",si[j]);
		printf("*********\n");*/
	}
}
int tt = 0 ; 
int ans[100005];
void print(int x)
{
    if(x == 0 )
		return;
	 print(last[x]);
     tt ++ ; 
	 ans[tt] = x; 
}
int main(){
	freopen("people.in","r",stdin);
	freopen("people.out","w",stdout);
    scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
	    scanf("%d %d",&a[i].s,&a[i].b);
        a[i].si = i ; 
	}
	sort(a+1,a+1+n,cmp);
	solve();
	printf("%d\n",top);
    print(si[top]);
	sort(ans+1,ans+1+tt);
	for(int i = 1;i <= tt; i ++)
	{
	    printf(i== 1?"%d":" %d",ans[i]);
	}
return 0;
}
