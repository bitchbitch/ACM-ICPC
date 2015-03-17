// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年03月18日 星期三 00时52分28秒

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
#define maxn 200005
using namespace std;
char  str1[maxn];
char  str2[maxn];
int dp[30][30];
int hs[30];
int main(){
   int n ; 
   scanf("%d",&n);
   scanf("%s %s",&str1[1],&str2[1]);
   int sum = 0 ; 
   for(int i = 1;i <= n;i ++)
   {
     if(str1[i] != str2[i])
	 {
	    dp[str1[i] - 'a'][str2[i]-'a'] = i ;
		sum ++ ;
		hs[str1[i] - 'a'] = i ; 
	 }
   }
   for(int i = 0;i < 26 ;i ++)
   {
     for(int j = 0 ;j < 26; j ++)
	 {
	   if(dp[i][j] != 0 && dp[j][i] != 0 )
	   {
	      printf("%d\n%d %d\n",sum-2,dp[i][j],dp[j][i]);
		  return 0 ; 
	   }
	 }
   }
   for(int i = 0 ;i < 26;i ++)
	   for(int j = 0 ;j < 26;j ++)
	   {
	      if(dp[i][j] != 0 && hs[j] != 0 )
		  {
	       printf("%d\n%d %d\n",sum-1,dp[i][j],hs[j]);
		   return 0 ; 
		  }
	   }
   printf("%d\n-1 -1\n",sum);
return 0;
}
