// File Name: hihointerview1.cpp
// Author: darkdream
// Created Time: 2014年08月18日 星期一 09时12分24秒

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
char str[200];
char ans[200];
int len ;
int solve(int k )
{
  for(int i = 1;;i ++)
  {
     if(k+i < len && k-i >= 0)
	 {
	     if(ans[k+i] != ans[k-i])
		 {
		    return 2 + 2 *(i-1); 
		 }
	 }else{
	    return 2 + 2*(i-1);
	 }
  }
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--)
  {
	  scanf("%s",str);
	  int t= -1 ;
	   len = strlen(str);
	  memset(ans,0,sizeof(ans));
	  for(int i = 0;i < len;i++)
	  {
	     if(str[i+1] == str[i])
		 {
		    for(int j = i+1; j <= len;j ++)
			{
			   if(str[j] != str[j-1])
			   {
				   i = j-1 ;
				   break;
			   }
			}
		 }else{
		   t++;
		   ans[t] = str[i]; 
		 }
	  }
	  //puts(ans);
	  int sum = 0 ; 
      sum = len - strlen(ans);
	  len = strlen(ans);
      int mx = 0 ;
	  for(int i = 0;i < len;i ++)
	  {
	     mx = max(solve(i),mx); 
	  }
    printf("%d\n",sum+mx); 
  }
  return 0;
}
