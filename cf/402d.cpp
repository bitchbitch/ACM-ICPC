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
int solve(int k ,int status)
{
	 cv = 0 ; 
     for(int i = 1;i <= tt;i ++)
	 {
	     if(k < prime[i] || k == 1)
			 return cv;
		 if(k % prime[i] == 0)
		 {
		    if(mp.find(prime[i]) != mp.end())
				cv +=status;
			else cv -=status ;
			k /= prime[i];
			i--;
		 }
	 }
	 if(mp.find(k) != mp.end())
		 cv+=status;
	 else cv -=status;
	 return cv;
}
int gcd(int a, int b)
{
  return b == 0?a:gcd(b,a%b);
}
int gcdv[maxn];
int dv[maxn];
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
	gcdv[0] = a[1];
	dv[0] = solve(a[1],1);
    for(int i = 1;i <= n;i ++)
	{
        gcdv[i] = gcd(gcdv[i-1],a[i]);
		if(gcdv[i] == gcdv[i-1])
		{
		  dv[i] = dv[i-1];
		}else{
		  dv[i] = solve(gcdv[i],1);
		}
	}
/*	for(int i = 1;i <= n;i ++)
		printf("%d ",gcdv[i]);
	printf("\n");
	for(int i = 1;i <= n;i ++)
		printf("%d ",dv[i]);
	printf("\n");
*/	int ok = 0  ; 
	int tmpgcd = 1; 
	int ans = 0 ; 
	for(int i = n;i >= 1;i --)
	{
       if(ok)
	   {
		   if(gcdv[i] != gcdv[i+1])
		   {
		        int tmp = solve(gcdv[i]/tmpgcd,1);
				//printf("***%d %d %d\n",gcdv[i],tmpgcd,gcdv[i]/tmpgcd);
				if(tmp > 0)
				{
			       tmpgcd = gcdv[i]	;
				}
		   }
	   }else{
	      if(dv[i] > 0 )
		  {
		    ok = 1; 
			tmpgcd = gcdv[i];
		  }
	   }
	   //printf("%d \n",tmpgcd);
       ans += solve(a[i]/tmpgcd,-1);
	}
	//printf("%d\n",si);
	printf("%d\n",ans);
return 0;
}
