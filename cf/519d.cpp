// File Name: 519d.cpp
// Author: darkdream
// Created Time: 2015年03月08日 星期日 11时45分15秒

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
int val[26];
map<LL,int> mp[26];
char str[100005];
int hs[26];
int main(){
   for(int i = 0 ;i < 26;i ++)
   {
      scanf("%d",&val[i]);
   }
   LL sum = 0 ; 
   scanf("%s",str);
   int len = strlen(str);
   LL ans = 0 ; 
   for(int i = 0  ;i < len ;i ++)
   {
       int k = str[i] -'a' ;
       if(hs[k] && mp[k][sum] != 0 )
	   {
	     ans += mp[k][sum];     
	   }
	   sum += val[k];
	   hs[k] = 1; 
       mp[k][sum] ++ ;
	   //printf("%d %lld\n",k,sum);
   }
   printf("%lld\n",ans);
return 0;
}
