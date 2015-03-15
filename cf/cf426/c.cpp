// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年04月28日 星期一 19时04分36秒

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
#include<queue>
using namespace std;


struct  cmp1{
  bool operator()(int x,int y)
  {
      return x > y ; 
  }
};
struct  cmp2{
  bool operator()(int x,int y)
  {
      return x < y ; 
  }
};
int a[300];
int main(){
  
	
  int n , k ; 
  scanf("%d %d",&n,&k);
  for(int i =1 ;i <= n;i ++)
  {
     scanf("%d",&a[i]);
  }
  int ans = a[1];
  priority_queue<int,vector<int>,cmp1> IN;
  priority_queue<int,vector<int>,cmp2> OUT;
  int sum[300];
  memset(sum,0,sizeof(sum));
  sum[1] = a[1];
  for(int i = 2;i <= n;i ++ )
  {
     sum[i] = sum[i-1] + a[i]; 
  }
  for(int begin = 1; begin <= n; begin ++  )
     for(int end = begin + 1 ; end <= n;end ++ )
	 {
	     int tsum = sum[end] - sum[begin-1];
		 ans = max(tsum,ans); 
         for(int i = begin;i <= end;i++)
		 {
		    IN.push(a[i]);
		 }
		 for(int i = 1;i < begin ;i ++)
			OUT.push(a[i]);
		 for(int i = end+1 ; i <= n  ;i ++)
			OUT.push(a[i]);
		 
		 for(int i = 1;i <= k;i ++)
		 {
		    if(IN.empty() || OUT.empty())
				break;
			int t1 = IN.top();
			int t2 = OUT.top();
			IN.pop();
			OUT.pop();
			tsum += t2 -t1; 
			ans = max(tsum,ans);
		 }
		 while(!IN.empty())  IN.pop();
		 while(!OUT.empty())  OUT.pop();
	 }
     printf("%d\n",ans);
return 0;
}
