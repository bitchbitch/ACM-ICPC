// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年10月07日 星期二 00时21分01秒

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
#define maxn 100004
#define M 1000000007
using namespace std;
int t, k ;

LL ans[maxn][2];
LL sum[maxn];
int main(){
  while(scanf("%d %d",&t,&k) != EOF)
  {
	 ans[1][1] = 1;
	 ans[0][2] = 1; 
	 
	 if(k == 1 )
	   ans[1][2] = 1;
	 else ans[1][2] = 0 ; 
     sum[0] = 0 ;
	 sum[1] = ans[1][1] + ans[1][2];
	 for(int i = 2; i <= 100000;i ++)
	 {
	     ans[i][1] = (ans[i-1][1] + ans[i-1][2])%M ;
		 if(i >= k )
		   ans[i][2] = (ans[i-k][1] + ans[i-k][2])%M;
		 else{
		   ans[i][2] = 0 ; 
		 }
		 sum[i] = (sum[i-1] + ans[i][1] + ans[i][2])%M;
	//    printf("%I64d\n",sum[i]);
	 }
	 int a, b; 
	 for(int i =1 ;i <= t;i ++)
	 {
	   scanf("%d %d",&a,&b);
	   printf("%I64d\n",((sum[b] - sum[a-1])+ M)%M );
	 }
	 
  }
return 0;
}
