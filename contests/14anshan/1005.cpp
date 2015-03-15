/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-09-13 14:02
 * Filename : 1005.cpp
 * Description :
 * *********************************************************/
/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-09-13 13:42
 * Filename : 1005.cpp
 * Description :
 * *********************************************************/
// File Name: 1005.cpp
// Author: darkdream
// Created Time: 2014年09月13日 星期六 13时07分58秒

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
double dp[10005][50];
vector<int> mp[60];
int num[60];
double x[60];
int n ,m, d;
int main(){
    int t; 
	scanf("%d",&t);
	while(t--)
	{
	  scanf("%d %d %d",&n,&m,&d);
	  int a, b;
	  memset(dp,0,sizeof(dp));
	  for(int i = 1;i <= m ;i ++)
	  {
	      scanf("%d %d",&a,&b);
		  mp[a].push_back(b);
		  mp[b].push_back(a);
	  }
	  double temp = 1.0/n;
	  for(int i = 1;i <= n;i ++)
	  {
	    dp[0][i] = temp;  
		num[i] = mp[i].size();
	    x[i] = 1.0;
	  }
	  for(int i = 0;i <= d ;i ++)
	  {
	     for(int j = 1;j <= n ;j ++)
		 {
			 x[j] = x[j] * (1-dp[i][j]);
             if(num[j] != 0 )
			   temp = dp[i][j]/num[j];
			 else temp = 0 ;
			 for(int s = 0 ;s < num[j] ;s ++)
			 {
			   dp[i+1][mp[j][s]] += temp;    
			 }
		 }
	  }
	  for(int i = 0;i <= d ;i ++)
	  {
	     for(int j = 1;j <= n ;j ++)
		 {
		    printf("%lf ",dp[i][j]);
		 }
		 printf("\n");
	  }
	  for(int i = 1;i <= n;i ++)
		  printf("%lf\n",x[i]);
	}
return 0;
}
