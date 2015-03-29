// File Name: 402d.cpp
// Author: darkdream
// Created Time: 2015年03月29日 星期日 16时42分46秒

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
#define maxn 32105
using namespace std;
int n , m; 
int a[maxn];
int b[maxn];
int prime[maxn];
int hs[maxn];
set<int> mp;
int tt; 
void sai()
{
	for(int i = 2;i < maxn ;i ++)
	{
	    int k = i * i ; 
		while(k < maxn)
		{
		  hs[k] = 1; 
		  k += i ; 
		}
	}
	
	for(int i = 2;i < maxn ;i ++)
	{
       if(hs[i] == 0 )
	   {
	      tt ++ ; 
		  prime[tt] = i ; 
	   }
	}
	//printf("%d\n",tt);
}
int cv ;
void solve(int k ,int status)
{
	 cv = 0 ; 
     for(int i = 1;i <= tt;i ++)
	 {
	     if(k < prime[i] || k == 1)
			 return;
		 if(k % prime[i] == 0)
		 {
		    if(mp.find(prime[i]) != mp.end())
				cv +=status;
			else cv -=status ;
			k /= prime[i];
			i--;
		 }
	 }
}
int gcd(int a, int b)
{
  return b == 0?a:gcd(b,a%b);
}
int gcdv[maxn];
int main(){
	sai();
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++ )
	{
	  scanf("%d",&a[i]);
	}
	for(int i = 1;i <= m;i ++)
	{
        scanf("%d",&b[i]);
        mp.insert(b[i]);	
	}
	int v, vsum,si;
	solve(a[1],1);
	si = 0 ;
	vsum =0 ; 
	v = cv;
	if(cv > 0)
	{
	   vsum = cv;
	   si = 1;
	}
	gcdv[1] = a[1];
    for(int i = 2;i <= n;i ++)
	{
        gcdv[i] = gcd(gcdv[i-1],a[i]);
		if(gcdv[i] != gcdv[i-1])
		{
	        solve(gcdv[i],1);
			v = cv;
		}
		if(v * i > vsum)
		{
		  vsum  = v * i ;
          si = i ;  
		}
	//	printf("%d\n",v);
	}
	for(int i = 1;i <= si ;i ++)
		a[i] /= gcdv[si];
	int ans = 0 ; 
	for(int i = 1;i <= n;i ++)
	{
	  solve(a[i],-1);
	  ans += cv;
	  //printf("%d\n",ans);
	}
	//printf("%d\n",si);
	printf("%d\n",ans);
return 0;
}
