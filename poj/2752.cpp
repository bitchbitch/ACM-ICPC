// File Name: 2752.cpp
// Author: darkdream
// Created Time: 2014年09月09日 星期二 21时26分40秒

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
char str[400005];
int next[400005];
int ans[400005];
int n; 
int len;
void solve()
{
   int k = -1 ; 
   int j = 0 ;
   next[0] = -1 ; 
   while(j <  len  )
   {
     if(k == -1 || str[k] == str[j])
	 {
	   k ++ ; 
	   j ++ ;
	   next[j] = k ; 
	 }else{
	   k = next[k];
	 }
   }
   int n = 1; 
   ans[1] = len; 
   k = next[len];
   while(k > -1)
   {
      n ++ ; 
	  ans[n] = k;
	  k = next[k];
   }
   sort(ans+1,ans+n+1);
   for(int i =2 ;i <= n;i ++)
	   printf(i == n?"%d":"%d ",ans[i]);
   printf("\n");
}
int main(){
  while(scanf("%s",str) != EOF)
  {
      len = strlen(str);
	  solve();
  }
return 0;
}
