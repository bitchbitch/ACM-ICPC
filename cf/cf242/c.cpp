// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年04月25日 星期五 15时21分10秒

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
#include<climits>

using namespace std;
int a[1000005];
int main(){
   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n; 
   scanf("%d",&n);
   int ans =0 ; 
   for(int i = 1 ;i <= n;i ++)
   {
	  int t ; 
	  scanf("%d",&t);
      ans = ans^t;
   }
   a[0] = 0 ; 
   for(int i = 1;i <= n;i ++)
   {
      a[i] = a[i-1]^i;
   }
   for(int i =1 ;i <= n;i ++)
   {
	  ans = ans ^ a[n % i];
	  if((n / i) % 2 == 1 )
		  ans = ans^a[i-1];
   }
   printf("%d\n",ans);
return 0;
}
