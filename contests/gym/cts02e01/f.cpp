// File Name: f.cpp
// Author: darkdream
// Created Time: 2014年09月11日 星期四 22时33分10秒

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

char str[100005][20];
int solve(int k )
{
  int mi = min(strlen(str[k]),strlen(str[k-1]));
  for(int i = 0;i <= 15;i ++)
  {
    if(str[k][i] != str[k-1][i])
		return i;
  }
  return mi;
}
int hs[100004];
int main(){
  memset(hs,0,sizeof(hs));
  int t = 1 ; 
  hs[1] = 0 ; 
  while(gets(str[t]))
  {
	  if(t!= 1)
	  {
	    int temp = solve(t);
		if(temp == 0 )
		{
		   hs[t] = 0 ;
		}else{
		   else if(temp == hs[t-1])
		   {
		     hs[t] = hs[t-1];
		   }
		   else hs[t] = hs[t-1] + 1; 
		}
	  }
	  t++;
  }
  for(int i = 1;i <= t;i ++)
  {
    for(int j = 1 ;j <= hs[i];j ++)
     printf(" ");
	puts(str[i]);
  }
   
return 0;
}
