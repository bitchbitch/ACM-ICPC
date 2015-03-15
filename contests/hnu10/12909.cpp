// File Name: 12909.cpp
// Author: darkdream
// Created Time: 2014年08月18日 星期一 10时01分22秒

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
int n , m; 
int a[100004];
int b[100005];
int cmp(int x , int y )
{
   return x > y ; 
}
int main(){
   while(scanf("%d %d",&n,&m) != EOF)
   {
     for(int i = 1;i <= n; i ++)
		 scanf("%d",&a[i]);
	 for(int j = 1;j <= m; j ++)
		 scanf("%d",&b[j]);
      sort(a+1,a+1+n,cmp);
	  sort(b+1,b+1+m,cmp);
	  int sum = 0 ; 
	  int t = a[1] + 1;
	  int ans = 0 ; 
	  int mx = 0 ; 
	  for(int i =1;i <= a[1] ;i ++)
		  ans += b[i];
	  mx = ans;
	
	  for(int i = 2;i <= n;i ++)
	  {
		 int k = min(m,t+a[i]-1);
	     ans-- ; 
		 for(;t <= k ; t++)
	     {
			 ans += b[t]; 
		 }
		 mx = max(mx,ans);
	  }
	  printf("%d\n",mx);
   }
return 0;
}
