// File Name: 351b.cpp
// Author: darkdream
// Created Time: 2015年03月25日 星期三 10时34分48秒

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
#define maxn 3005
using namespace std;
int a[maxn]; 
int tree[maxn];
int lowbit(int x)
{
   return x & -x ; 
}
int n ;
void update(int x)
{
    while(x <= n)
	{
	   tree[x] += 1;
	   x += lowbit(x);
	}
}
int  getsum(int x)
{
  int ans = 0 ; 
  while(x >= 1 )
  {
     ans += tree[x];
	 x -= lowbit(x);
  }
  return ans ;
}
int main(){
    scanf("%d",&n);
	int nx = 0 ; 
	for(int i= 1;i <= n;i ++)
	{
	  scanf("%d",&a[i]);
      nx += i - getsum(a[i]) - 1;
	  //printf("%d\n",nx);
	  update(a[i]);
	}
	if(nx % 2 == 1 )
		printf("%lf",2*nx-1.0);
	else printf("%lf",2.0*nx);
     	
return 0;
}
