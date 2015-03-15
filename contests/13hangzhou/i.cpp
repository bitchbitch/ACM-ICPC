// File Name: i.cpp
// Author: darkdream
// Created Time: 2014年05月11日 星期日 19时55分05秒
#pragma comment(linker,"/STACK:102400000,102400000")

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

using namespace std;

int bags[25][10];
int vis[1 << 22];
int re[1 << 22][10];
int dp[1 << 22];
int resum[1 << 22];
int num_bag,num_color,s,limits,total_num;
int dfs(int u,int left){
    if(left == 0 )
       return 0;
    if(vis[u])
        return dp[u];
    vis[u] = 1; 
    for(int i = 0 ;i <num_bag;i ++)
    {
       if((u >> i)^1)
       {
          int tu = u^(1 << i);
          int tsum = resum[tu] - resum[u];
          if(tsum > 0)
           dp[u] = max(dp[u],tsum + dfs(tu,left - tsum));
          else dp[u] = max(dp[u],left - dfs(tu,left));
       }
    }
    return dp[u];
}
int main(){

    while(scanf("%d %d %d",&num_color,&num_bag,&s) != EOF){
    
        if(!num_color)
            break;
        
        memset(bags,0,sizeof(bags));
        memset(re,0,sizeof(re));
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(resum,0,sizeof(resum));

        for(int i = 0  ;i < num_bag;i ++){
             int temp; 
             scanf("%d",&temp);
             for(int j = 1;j <= temp ;j ++){
                int tc; 
                scanf("%d",&tc);
                bags[i][tc] ++ ; 
             }
        }
        limits = (1 << num_bag) -1;

        for(int i = 0 ;i <= limits ;i ++ ){
            int t = 0 ; 
            int temp = i ; 
            while(temp){
               if(temp % 2){
                 for(int j = 1 ;j <=num_color;j ++){
                   re[i][j] += bags[t][j]; 
                 }
               }
               t++; 
               temp /= 2 ; 
            }
            for(int j = 1 ;j <= num_color; j ++)
            {
                  resum[i] +=  re[i][j]/s;
                  re[i][j] %= s; 
            }
        }
        total_num = resum[limits];
        for(int i = 0 ;i <= limits ;i ++)
            dp[i] = 0 ; 
        int ans = dfs(0,total_num);
        printf("%d\n",2*ans -total_num );
    }
    return 0;
}
