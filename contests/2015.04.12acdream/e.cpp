// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 13时56分11秒

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
int t; 
int n ;
int gcd(int a, int b )
{
   return b == 0 ?a:gcd(b,a%b);
}
int main(){
    cin >> t; 
	int tmp ; 
	while(t--){
	   cin >> n;
	   cin >> tmp ;
	   int ans = tmp ; 
	   int mx = tmp ;
	   for(int i = 1;i < n;i ++)
	   {
		   cin >> tmp;
		   ans = gcd(ans,tmp);
		   mx =max(tmp,mx);
	   }
	   if((mx/ans - n)%2 ==0 )
		   printf("Lose\n");
	   else printf("Win\n");
	}
return 0;
}
