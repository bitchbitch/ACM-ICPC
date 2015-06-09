// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月07日 星期日 11时42分01秒

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
int a[105];
int n;
int dp[105][105];
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    time_t be,en;
    be = clock();
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i = 0 ;i <= n;i ++){
           scanf("%d",&a[i]);  
        }
        for(int i = n;i >= 1;i --)
        {
            for(int j = i+1;j <= n ;j ++){
                dp[i][j] = min(dp[i][j-1] + a[i-1]*a[j-1]*a[j],dp[i+1][j] + a[i-1]*a[i]*a[j]) ;
                for(int s = i + 1; s < j; s ++)
                    dp[i][j] = min(dp[i][j],dp[i][s] + dp[s+1][j] + a[i-1]*a[s]*a[j]) ;
            }
        }
        printf("%d\n",dp[1][n]);
    }
    en = clock();
    printf("%lf\n",(en-be)*1.0/CLOCKS_PER_SEC);
return 0;
}
