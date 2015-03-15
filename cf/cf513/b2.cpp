// File Name: b2.cpp
// Author: darkdream
// Created Time: 2015年02月08日 星期日 02时02分39秒

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
#define LL __int64

using namespace std;
LL a[55];
LL n , m;
LL P(LL x, LL t)
{
  LL ans = 1; 
  for(LL i = 1;i <= t; i ++)
  {
    ans *= x; 
  }
  return ans;
}
void fan(LL i, LL j)
{
  //printf("***%I64d %I64d\n",i,j);
  for(LL s = i ; s <= (i+j)/2; s ++)
  {
     swap(a[s],a[j-(s-i)]);
  }
}
void solve(LL x,LL k)
{
 // printf("%I64d %I64d\n",x,P(2,k-2));
  if(k == 1)
	  return;
  if(x > P(2,k-2))
  {
    solve(P(2,k-1)-x + 1,k-1);
    fan(n-k+1,n);
  }else{
    solve(x,k-1);
  }
}
int main(){
  scanf("%I64d %I64d",&n,&m);
  for(LL i = 1 ;i <= n;i ++)
  {
    a[i] = i ; 
  }
  solve(m,n);
  for(LL i = 1;i <= n;i ++)
	  printf("%I64d ",a[i]);
  printf("\n");
return 0;
}
