// File Name: 429b.cpp
// Author: darkdream
// Created Time: 2015年03月08日 星期日 10时13分53秒

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
int a[1005][1005];
int ldp[1005][1005];
int rdp[1005][1005];
int udp[1005][1005];
int ddp[1005][1005];
int main(){
  int n , m; 
  scanf("%d %d",&n,&m);
  for(int i =1;i <= n;i ++)
	  for(int j = 1;j <= m;j ++)
		  scanf("%d",&a[i][j]);
  for(int i = 1;i <= n;i ++)
  {
     for(int j = 1;j <= m;j ++)
	 {
	    ldp[i][j] = a[i][j] + max(ldp[i][j-1],ldp[i-1][j]);
	 }
  }
  for(int i = n;i >=1;i --)
  {
     for(int j = 1;j <= m;j ++)
	 {
	    rdp[i][j] = a[i][j] + max(rdp[i][j-1],rdp[i+1][j]);
	 }
  }
  for(int i = n;i >=1;i --)
  {
     for(int j = m;j >=1;j --)
	 {
	    udp[i][j] = a[i][j] + max(udp[i][j+1],udp[i+1][j]);
	 }
  }
  for(int i = 1;i <= n;i ++)
  {
     for(int j = m ;j >=1 ;j --)
	 {
	    ddp[i][j] = a[i][j] + max(ddp[i][j+1],ddp[i-1][j]);
	 }
  }
  int sum = 0 ; 
  for(int i = 2;i < n;i ++)
	  for(int j = 2;j < m;j ++)
	  {
		  int tsum = sum; 
	      sum = max(sum,ldp[i-1][j] + udp[i+1][j] + rdp[i][j-1] + ddp[i][j+1]) ;  
	      sum = max(sum,rdp[i+1][j] + ddp[i-1][j] + ldp[i][j-1] + udp[i][j+1]) ;  
	  }
  printf("%d\n",sum);
return 0;
}
