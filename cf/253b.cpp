// File Name: 253b.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 16时24分14秒

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
int n; 
int ans[5005];
int hs[5005];
int main(){
	int n; 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	memset(hs,0,sizeof(hs));
    for(int i =1;i<=n;i ++)
	{
	  int temp ; 
	  scanf("%d",&temp);
	  hs[temp] ++ ; 
	}
    int minn = 1e8;
	ans[0] = 0;
	for(int i =1;i <= 5000 ;i ++)
		ans[i] = ans[i-1]+ hs[i];
	for(int i=1 ;i<= 2500 ;i ++) 
	{
	   minn = min(ans[i-1] + (ans[5000] - ans[2*i]),minn);
	}
	printf("%d\n",minn);
return 0;
}
