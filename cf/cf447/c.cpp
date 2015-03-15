// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年07月13日 星期日 21时23分38秒

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
#include<queue>

using namespace std;
int n; 
int a[100005];
int b[100005];
struct node{
 int v ;
 int isv;
}dp[100005];
int main(){
   int n; 
   memset(b,0,sizeof(b));
   scanf("%d",&n);
   a[0] = -100 ;
   dp[0].v = 0 ; 
   dp[0].isv = 0 ; 
   int M = n == 1?1:2; 
   for(int i =1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
   }
   for(int i = 1;i <= n;i++)
   {
       if(a[i] > a[i-1]) 
	   {
	      dp[i].v = dp[i-1].v +1;
	     if(i >= 2 && a[i-1] <= a[i-2])
		 {
	       	 if(a[i-1] > a[i-3] +1 || a[i] > a[i-2]+1)
				 dp[i].isv = dp[i-1].isv + 1;
			 dp[i].isv = max(dp[i].isv,3);

		 }else dp[i].isv = dp[i-1].isv +1;
	   }else{
	       dp[i].v = 1; 
		   dp[i].isv = dp[i-1].v + 1;
	   }
	   M = max(dp[i].v,M);
	   M = max(dp[i].isv,M);
   }
   printf("%d\n",M);
return 0;
}
