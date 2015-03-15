// File Name: 买票.cpp
// Author: darkdream
// Created Time: 2014年05月15日 星期四 01时16分45秒

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
#define M 100000007
long long c[1000][1000];
void solve(){
   memset(c,0,sizeof(c));
   c[0][0] = 1;
   for(int i = 1; i <= 300 ;i++)
	   c[i][0] = 1;
   for(int i = 1;i <= 300 ;i ++)
	   for(int j = 1; j<= i ;j ++)
		   c[i][j] = (c[i-1][j]+c[i-1][j-1])%M;
}
int main(){
    solve();
	int t; 
	scanf("%d",&t);
	while(t--)
	{
	    int n , m;
		scanf("%d %d",&n,&m);
		if(m == 0 )
			printf("1\n");
		else if(m == 1)
			printf("%lld\n",c[n+1][1]);
		else if(m == 2)
			printf("%lld\n",c[n+1][2]);
		else 
		printf("%lld\n",(M+c[n+m][m]-c[n+m][m-3])%M);
	}

	return 0;
}
