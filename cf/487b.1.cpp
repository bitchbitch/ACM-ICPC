// File Name: 487b.1.cpp
// Author: darkdream
// Created Time: 2015年03月23日 星期一 15时24分56秒

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
#define N 100007
using namespace std;
multiset<int> st,rt;
int dp[N],n,l,s,a[N];
int main(){
  scanf("%d %d %d",&n,&s,&l);
  for(int i = 1;i <= n;i ++)
	  scanf("%d",a+i);
  for(int i = 1,j = 1;i <= n;i ++)
  {
      st.insert(a[i]);
	  for(;*st.rbegin() - *st.begin() > s;j ++)
	  {
	      st.erase(st.find(a[j]));
		  if(i - j >= l) rt.erase(rt.find(dp[j-1]));
	  }
	  if(i - j + 1 >= l) rt.insert(dp[i-l]);
	  if(rt.begin() == rt.end())  dp[i] = N;
	  else dp[i] = *rt.begin() + 1; 
  }
  printf("%d\n",dp[n] >= N?-1:dp[n]);
return 0;
}
