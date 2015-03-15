// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年11月11日 星期二 23时28分50秒

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
char str[100005];
int num[100005];
int vis[100005];
int dp[400005];
  int n , p ; 
int solve(int t)
{
    if(t <= 0 )
	{
	  return n + t;  
	}
	if(t > n)
		return  t- n ;
}
int main(){
  scanf("%d %d",&n,&p);
  scanf("%s",&str[1]); 
  int sum = 0 ;
  int num = 0 ; 
  for(int i = 1;i <= n/2;i ++)
  {
	 if(str[i] == str[n-i+1])
		 continue;
	 num ++ ; 
     int mi = min(str[i],str[n-i+1]) ;
	 int mx = max(str[i],str[n-i+1]);
     sum += min(mx - mi,mi + 26 -mx);
     vis[i] = 1; 
	 vis[n-i+1] = 1; 
  }
  if(sum == 0 )
  {
     printf("0\n");
	 return 0 ;
  }
  
	 int be = 0 ; 
	 int en = 0 ;
	 int qd ;
	 int zd;
	 if(p > n/2)
	 {
	   qd = n/2 +1;
	   zd = n;
	 }else {
	   qd = 1; 
	   zd = n/2;
	 }
	 
     for(int i = qd;i <= zd;i ++)
	 {
	     if(!be && vis[i] ==1 )
			 be = i ; 
		 if(vis[i])
			en = i ; 
	 }
	 //printf("%d %d\n",be,en);
	 if(p >= en)
		 sum +=  p - be;
	 else if(p <= be)
		 sum +=  en - p;
	 else sum += min(p-be,en-p) + en -be;
	 printf("%d\n",sum);
return 0;
}
