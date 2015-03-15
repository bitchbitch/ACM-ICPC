// File Name: 167.cpp
// Author: darkdream
// Created Time: 2014年08月15日 星期五 11时35分50秒

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

int a[20][20];
int dp[20][20][300];
int dis[20][20][20];
int main(){
   int n , m , k ; 
   scanf("%d %d %d",&n,&m,&k);
   memset(dp,0,sizeof(dp));
   for(int i = 1;i <= n;i ++)
   {
     for(int j = 1;j <= n;j ++)
	 {
	     scnaf("%d",&dp[i][j][1]);      
	 }
   }   
   for(int i = 1;i <= n;i ++)
   {
        
   }
	   
return 0;
}
