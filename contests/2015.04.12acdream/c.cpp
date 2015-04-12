// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年04月12日 星期日 19时52分24秒

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
int t; 
int n; 
int sum[100005]; 
int mxsum[100005];
int a[100005];
int main(){
	scanf("%d",&t);
	while(t--)
	{	
      int n ; 	
	  memset(sum,0,sizeof(sum));
	  scanf("%d",&n);
	  int tsum = 0 ; 
	  int ans = 0 ; 
	  int asum = 0 ; 
	  for(int i = 1;i <= n;i ++)
	  {
	       scanf("%d",&a[i]) ;
		   if(tsum  <= 0 )
		   {
		     tsum = 0 ; 
		   }
		   asum += a[i];
		   tsum += a[i];
		   mxsum[i] = max(mxsum[i-1],asum);
		   ans = max(ans,tsum);
	  }
	  tsum = 0 ; 
	  for(int i = n; i >= 1;i--){
	     tsum +=a[i];
		 ans = max(tsum+mxsum[i-1],ans) ;
	  } 
      printf("%d\n",ans);
	}
return 0;
}
