// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年01月18日 星期日 13时54分20秒

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
#define maxn 10000007
using namespace std;
int hs[maxn];
int ans[maxn];
void solve()
{
	memset(ans,0,sizeof(ans));
	memset(hs,0,sizeof(hs));
    for(int i = 2 ;i <= maxn;i ++)
	{
	    if(hs[i]  == 0  )
		{
			int k = i; 
 		    while(k < maxn-5)
			{
		      hs[k] = 1;
			  ans[k] ++  ; 
			  k += i ; 
			}
		}
	}
}
int main(){
  int T;
  solve();
  //freopen("","r",stdin);
  //freopen("out","w",stdout);
  scanf("%d",&T);
  for(int ca = 1; ca <= T; ca ++)
  {
     int n , m , t; 
	 scanf("%d %d %d",&n,&m,&t);
	 int sum = 0 ; 
	 for(int i = n ;i <= m;i ++)
	 {
	   //printf("%d ",ans[i]);
	   if(ans[i] == t )
		   sum ++ ; 
	 }
	 //printf("\n");
	 printf("Case #%d: %d\n",ca,sum);
  }
return 0;
}
