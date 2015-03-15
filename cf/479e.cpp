// File Name: 479e.cpp
// Author: darkdream
// Created Time: 2015年03月08日 星期日 21时37分17秒

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
#define maxn 5005
#define M 1000000007
LL dp[maxn];
LL tmp[maxn];
int main(){
   int n,a,b,k; 
   scanf("%d %d %d %d",&n,&a,&b,&k);
   dp[a] = 1;
   for(int i = 1;i <= k ;i ++)
   {
	 memset(tmp,0,sizeof(tmp));
     for(int j = 1;j <= n ;j ++)
	 {
		 if(j == b )
			 continue;
		 int dis = abs(j-b)-1;
	     int l = max(j-dis,1); 
		 int r = min(n,j+dis);
		 tmp[l] = (tmp[l]+dp[j])%M;
		 tmp[j] = (tmp[j]-dp[j])%M;
		 tmp[j+1] =(tmp[j+1]+dp[j])%M;
		 tmp[r+1] =(tmp[r+1]-dp[j])%M;
	 }
	 for(int j = 1;j <= n;j ++)
	 {
        tmp[j] = (tmp[j-1] +M + tmp[j])%M;	
	 }
	 for(int j= 1;j <= n;j ++)
		 dp[j] = tmp[j];
	 dp[b] = 0;
   }
   LL sum =0 ; 
   for(int i = 1;i <= n;i ++)
   {
      sum = (sum + dp[i]) % M;
	  //printf("%lld ",dp[i]);
   }
   printf("%lld\n",sum);
return 0;
}
