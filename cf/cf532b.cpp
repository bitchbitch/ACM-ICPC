// File Name: cf532b.cpp
// Author: darkdream
// Created Time: 2015年04月19日 星期日 21时24分22秒

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
vector<int >mp[200005];
int val[200005];
LL mx[200005][2];
LL add[2];
LL ans = 0 ; 
void  dfs(int k )
{
	mx[k][1] = val[k];
	for(int i = 0 ;i < mp[k].size() ;i ++){
		dfs(mp[k][i]);
	    add[0] = max()	
	}
	ans = max(mx[k][1],ans);
}
int main(){

	int n ; 
	int ta,tb;
	memset(mx,-1,sizeof(mx));
	scanf("%d",&n);
	scanf("%d %d",&ta,&tb);
	val[1] = tb; 
    for(int i = 2;i <= n;i ++){
		scanf("%d %d",&ta,&tb);
		mp[ta].push_back(i);
		val[i] = tb; 
	}
	dfs(1);
	for(int i = 1;i <= n;i ++)
		printf("%lld %lld\n",mx[i][1],mx[i][0]);
	printf("%lld\n",ans);
return 0;
}
