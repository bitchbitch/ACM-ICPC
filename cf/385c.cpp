// File Name: 385c.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 18时24分53秒

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
const int maxn = 1000000*10 + 1000; 
int      ans[maxn];
int       hs[maxn];
int      ahs[maxn];
int n ;
void solve()
{
   //int tmp = sqrt(maxn); 
   for(int i = 2;i < maxn;i ++)
   {
       if(hs[i] == 0)
	   {
		  for(int j = i ;j < maxn;j += i)
		   {
			  
			  ans[i] += ahs[j] ;
		      hs[j] = 1; 
		  }
	   }
   }
   for(int i = 2;i <= maxn;i ++)
   {
     ans[i] += ans[i-1];
   }
}
int main(){
  memset(ans,0,sizeof(ans));
  memset(hs,0,sizeof(hs));
  memset(ahs,0,sizeof(ahs));
  scanf("%d",&n);
  int _max = 0;
  for(int i = 1;i <= n;i ++)
  {
	 int tmp ; 
     scanf("%d",&tmp);
	 ahs[tmp] ++;
	 _max = max(tmp,_max);
  }
  solve();
  int m ; 
  scanf("%d",&m);
  for(int i = 1;i <= m;i ++)
  {
    int l , r; 
	scanf("%d %d",&l,&r);
	if(l > _max)
	{
	  printf("0\n");
	  continue;
	}
	r = min(r,_max);
	printf("%d\n",ans[r] - ans[l-1]);
  }
return 0;
}
