// File Name: c1.cpp
// Author: darkdream
// Created Time: 2014年07月13日 星期日 21时42分30秒

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
int a[100005];
int ans[100005];
int last[100005];
int n; 
int main(){
   scanf("%d",&n);
   int t = 0;
   last[0] = 0 ;
   a[0] = -1000000 ; 
   int M = 0; 
   memset(last,0,sizeof(last));
   memset(ans,0,sizeof(ans));
   for(int i =1 ;i <= n;i ++)
   {
	   scanf("%d",&a[i]);
       if(a[i] <= a[i-1])
	   {  
		  last[i] = 1;
		  ans[t] = i -1;
		  t = i;
	   }else{
	     last[i] = last[i-1] +1;
	   }
      M = max(last[i],M);
   }
   if(M != n)
	   M ++;
  // printf("%d\n",M);
   ans[t] = n; 
   ans[1] = 1;
  // for(int i =1 ;i <= n;i ++)
	//  printf("%d ",ans[i]);
   for(int i = 1;i <= n;i ++)
   {
      if(ans[i])
	  {
	      int temp = a[i-1] + 1;
		  if(a[i+1] > temp)
		  {
		    M = max(M,ans[i]-i+1 +last[i-1]);
		  }else{
		    M = max(M,last[i-1] +1);
		  }
	  }
	  if(ans[i+1])
	  {
	     int temp = a[i-1] + 1;
		 if(a[i+1] > temp)
		 {
		   M = max(M,last[i] + last[ans[i+1]]);
	     }	 
	  }
   }
   printf("%d\n",M);
return 0;
}
