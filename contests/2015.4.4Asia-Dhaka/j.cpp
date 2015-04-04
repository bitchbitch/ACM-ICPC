// File Name: j.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 15时35分41秒

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
#define M 1000000007

using namespace std;
int t ;
int p ;
int hs[1000005];
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);


	scanf("%d",&t);
	for(int CA = 1; CA <= t ;CA ++)
	{
        scanf("%d",&p);
		memset(hs,0,sizeof(hs));
        int ta,tb;
		int tsum = 0 ; 
		for(int i = 1;i <= p ;i ++)
		{
	       scanf("%d %d",&ta,&tb);     	
		   hs[ta] += tb;
		   tsum += tb;
	    }		
		LL sum = 0 ;
		LL ans = 0 ; 
		int k = 0 ; 
		p = 0 ;
		for(int i = 0;i <= 200000 ;i ++)
		{
		  if(hs[i])
		  {
			p ++ ;
	   	    sum = (sum+hs[i])%M; 
			ans = (ans + 1ll*hs[i]*sum) % M; 
		  }
		}
		 if(p ==1 )
			 k = 1; 
		 else k = 2; 
		 printf("Case %d: %lld %d\n",CA,ans,k);
	}
return 0;
}
