// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年03月21日 星期六 14时05分54秒

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
int n , m;
int sum[10005];
int main(){
	 freopen("matrix.in","r",stdin);
	 freopen("matrix.out","w",stdout);
     scanf("%d %d",&n,&m);
	 int ta,tb;
	 for(int i = 1;i <= m;i ++)
	 {
	       scanf("%d %d",&ta,&tb);;
		   sum[ta]++;
		   sum[tb]++;
	 }
	 LL ans = 0 ; 
	 for(int i= 1;i <= n;i ++)
	 {
	     ans += sum[i]*sum[i];
	 }
	 printf("%I64d\n",ans);
return 0;
}
