// File Name: b.cpp
// Author: darkdream
// Created Time: 2013年11月26日 星期二 23时40分21秒

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

int a[100005];
int ans[100005];
int hs[100005];
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
  int n ,m;
  scanf("%d %d",&n,&m);
  memset(ans,0,sizeof(ans));
  memset(hs,0,sizeof(hs));
  for(int i =1 ;i <= n;i ++)
	  scanf("%d",&a[i]);
  int t = 0 ; 
  for(int i = n;i >= 1; i--)
  {
	if(hs[a[i]] == 0 )
	{ 
		hs[a[i]] = 1;
	    t ++;
	}
    ans[i] = t; 
  }
  for(int i =1 ;i <= m;i ++)
  {
    int temp ; 
	scanf("%d",&temp);
	printf("%d\n",ans[temp]);
  }


return 0;
}
