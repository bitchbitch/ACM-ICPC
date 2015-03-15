// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 00时57分59秒

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
const int maxn = 1000010;
map<int ,int >mp;
map<int ,int >be;
int a[maxn];
int num[maxn];
int n;
int anst[maxn];
int lowbit(int x)
{
    return x &(-x);
}
void update(int x,int st)
{
   while(x <= n)
   {
      anst[x] += st;
	  x += lowbit(x);
   }
}
LL getsum(int x)
{
  LL sum = 0 ; 
  while(x >= 1 )
  {
    sum +=  anst[x];
	x -= lowbit(x);
  }
  return sum;
}
int main(){
	scanf("%d",&n);
	int temp ; 
	mp.clear();
	be.clear();
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = n;i >= 1; i --)
	{
         int t= mp[a[i]];
		 mp[a[i]]++;
		 num[i] = t+1;
		 update(t+1,1);
	}
	LL ans = 0 ; 
	for(int i = 1;i <= n;i ++)
	{
        int t = be[a[i]];
		update(num[i],-1);
		be[a[i]] = t + 1; 
		//printf("%I64d\n",getsum(t));
		ans += getsum(t);
	}
	printf("%I64d\n",ans);
	return 0 ;
}
