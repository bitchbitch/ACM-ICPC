// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年07月27日 星期日 12时21分05秒

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

using namespace std;
#define LL long long 
char str[100005];
struct node{
  int ans ; 
  int num2  ; 
  int num1; 
}dp[100005];
int main(){
   int n ;
   while(scanf("%d",&n) != EOF){
     memset(dp,0,sizeof(dp));
	   scanf("%s",&str[1]);
      int len = strlen(&str[1]);
	  LL sum = 0 ; 
	  for(int i =1 ;i <= len ;i ++)
	  {
	      if(str[i] == '2' )
		  {
		    if(dp[i-1].num2*2 + dp[i-1].num1 <= n-2)
			{
			   dp[i].num2 = dp[i-1].num2 + 1; 
			   dp[i].num1 = dp[i-1].num1 ;
			   dp[i].ans = dp[i-1].ans + 1; 
			}else{
			   dp[i].num2 = dp[i-1].num2 ; 
			   dp[i].num1 = dp[i-1].num1 ;
			   dp[i].ans = dp[i-1].ans ; 
			}
		  }else {
		    if(dp[i-1].num2*2 + dp[i-1].num1 < n )
			{
			   dp[i].num2 = dp[i-1].num2; 
			   dp[i].num1 = dp[i-1].num1 +1;
			   dp[i].ans = dp[i-1].ans + 1; 
			   
			}else if(dp[i-1].num2 != 0){
			   dp[i].num2 = dp[i-1].num2-1; 
			   dp[i].num1 = dp[i-1].num1 +1;
			   dp[i].ans = dp[i-1].ans; 
			}else{
			   dp[i].num2 = dp[i-1].num2 ; 
			   dp[i].num1 = dp[i-1].num1 ;
			   dp[i].ans = dp[i-1].ans ; 
			}
		  }
		  sum += dp[i].ans;
	//	  printf("%d\n",dp[i].ans);
	  }
	  printf("%I64d\n",sum);
   }
   
return 0;
}
