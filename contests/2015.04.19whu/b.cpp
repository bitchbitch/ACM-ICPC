// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月19日 星期日 12时40分22秒

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
int n;
int a[1000005];
int main(){
	int n ; 
	while(scanf("%d",&n) != EOF){
	   int sum = 0  ; 
	   int tsum  = 0 ; 
	   int mx = 0 ; 
	   int tmp ; 
	   for(int i = 1;i <= n;i ++)
	   {
		scanf("%1d",&tmp);
		sum += tmp ; 
		  if(tsum < 0 )
			  tsum = 0 ; 
		  tsum += (10-tmp)%10 - tmp;
		  mx = max(tsum,mx);
	   }
	   //printf("%d\n",mx);
	   printf("%d\n",mx+sum);
	}
return 0;
}
