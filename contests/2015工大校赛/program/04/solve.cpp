// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 21时13分05秒

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
LL dp[100][100];
int main(){
    int n , m ,T;
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
      scanf("%d %d",&n,&m);   
      memset(dp,0,sizeof(dp));
      dp[0][0] = 1; 
      for(int i = 1;i <= n + m ;i ++){
             int k = i/2; 
             if(i % 2 == 1)
                 k ++ ; 
         if(i == 5){
            for(int j = k; j <= min(i,n) ;j ++)
                dp[i][j] = dp[i-1][j-1];
         }else if(i == 8 ){
            for(int j = k; j <= min(i,n) ;j ++)
                dp[i][j] = dp[i-1][j];
         }else{
             for(int j = k ;j <= min(i,n); j ++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
             }
         }
      }
      printf("%lld\n",dp[n+m][n]);
    }

return 0;
}
