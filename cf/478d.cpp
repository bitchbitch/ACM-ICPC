// File Name: 478d.cpp
// Author: darkdream
// Created Time: 2015年03月13日 星期五 08时42分21秒

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
#define maxn 410005
#define M 1000000007
using namespace std;
LL dp[maxn] ;
int main(){
    int n , m;
	scanf("%d %d",&n,&m);
    dp[0] = 1;
	int flor  = 1 ; 
	for(flor ;;flor ++ )
	{
	   if(flor*(flor+1) /2 <= n + m && (flor+2)*(flor+1)/2 > n + m )
		   break;
	}
    for (int i = 1;i <= flor ;i ++)	
	{
	     int mx = i*(i+1)/2;
		 int tt = min(mx,n);
		 for(int j = tt ;j >= 0; j --)
		 {
		    if(mx -j > m)
			{
			  dp[j] = 0 ; 
			}
			if(j <= n && j -i >= 0 )
				dp[j] =(dp[j]+dp[j-i]) % M;
		 }
	}
	LL sum = 0 ; 
    for(int i = 0;i <= n;i ++)
	{
	      sum = (sum + dp[i]) % M ;
	}
    printf("%lld\n",sum);
return 0;
}
