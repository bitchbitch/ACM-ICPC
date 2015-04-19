// File Name: f.cpp
// Author: darkdream
// Created Time: 2015年04月19日 星期日 13时11分18秒

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
int  n;
char a[100];
LL solve(int l , int r ){
	 LL ans = 0 ;
	 for(int i = l ;i <= r ;i ++)
		 ans = ans * 10 + a[i]-'0';
	 return ans;
}
int main(){
	while(scanf("%s",a) != EOF){
	   LL ans = 1ll*1e9*1e8;
	   n = strlen(a);
	   for(int i = 0;i < n-1  ;i ++)
	   {
		   ans = min(ans,abs(solve(0,i)-solve(i+1,n-1)));
		  // printf("%lld %lld\n",solve(0,i),solve(i+1,n-1));
	   }
	   printf("%lld\n",ans);
	}
return 0;
}
