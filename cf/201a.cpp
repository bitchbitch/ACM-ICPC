// File Name: 201a.cpp
// Author: darkdream
// Created Time: 2015年03月10日 星期二 20时15分18秒

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
int dp[105];
int mx[105];
int main(){
   int n ;
   scanf("%d",&n);
   dp[1] = 1;
   dp[2] = 3;
   dp[4] = 3; 
   dp[5] = 3; 
   for(int i = 5;i <= 30;i +=2)
   {     
	   int  t = i /2;
       mx[i] = (t/2)*4 + 1; 
	   int k ; 
	   if(t % 2 == 0 )
		  k= t*t *2;
	   else
		  k=((t/2+1)*(t/2+1) + (t/2)*(t/2))*4;   
	   mx[i] +=k; 
	   for(int j =1 ;j <= min(mx[i],100) ;j ++)
	   {
		   if(dp[j] == 0 )
		   {
			   dp[j] = i ; 
		   }
	   }
   }
   printf("%d\n",dp[n]);
return 0;
}
