// File Name: g.cpp
// Author: darkdream
// Created Time: 2015年03月15日 星期日 16时21分03秒

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

int mp[105][105];
int vmp[105][105];
int vish[105];
int visl[105];
int hsh[105];
int hsl[105];
int sumh;
int suml;
int x
int n,m,k;
int ans = 0;
int x[5] = {0,0,1,-1};
int y[5] = {1,-1,0,0};
void solve(int k )
{
	memset(hsh,0,sizeof(hsh));
	memset(hsl,0,sizeof(hsl));
    sumh = 0 ; 
	suml = 0 ; 
}
int main(){
    int t; 
	scanf("%d",&t);
    while(t--)
	{
	  scanf("%d %d %d",&n,&m,&k);
      ans = 0 ; 
	  for(int i = 1;i <= k ;i ++)
	  {
	     double tx,ty;
		 scanf("%lf %lf",tx,ty);
		 mp[int(tx+1.0)][int(ty+1.0)] = 1; 
		 if(vish[int(ty+1.0)] == 0)
		 {
		     ans ++ ; 
			 vish[int(ty+1.0)] = 1; 
		 }
	  }
      for(int i = 1;i <= m;i ++)
	  {
	     if(hsl[i] == 0 )
		 {
		    solve(i);
		 }
	  }
	}
return 0;
}
