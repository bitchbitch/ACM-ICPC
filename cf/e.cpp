// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年01月28日 星期三 01时24分08秒

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
struct node{
  int x, y ; 
}kh[605];
int dp[1300][1300];

int n ; 
int find(int r,int c)
{
   if(c == 0)
	   return 1; 
   int ok = 0 ; 
   for(int i)
}
int main(){
  int n ; 
  scanf("%d",&n);
  for(int i = 1;i <= n;i ++)
  {
    scanf("%d %d",&kh[i].x,&kh[i].y);
	kh[i].x/= 2; 
	kh[i].y/= 2; 
  }
  memset(dp,0,sizeof(dp));
  int ok = 1 ; 
  for(int i = n;i >= 0 ;i --)
  {
	 int tok = 0;
	 for(int j = kh[i].x ;j <= kh[i].y; j ++)
	 {
	    dp[i][j] = find(i,j);
		if(dp[i][j])
			tok = 1; 
	 }
	 if(tok = 0 )
		 ok = 0;
  }
  if(ok == 0 )
	  printf("IMPOSSIBLE\n");
  else{
   
  }
return 0;
}
