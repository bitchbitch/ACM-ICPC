// File Name: test.1.cpp
// Author: darkdream
// Created Time: 2014年10月30日 星期四 21时24分02秒

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
struct node{
	int nx;
	int val ;
	node(){}
	node(int _nx,int _val)
	{
	  nx = _nx; 
	  val = _val;
	}
};
vector<node> mp[10];
int val[10];
int vval[10];
int ans = -1e9;
void dfs(int k ,int v)
{
     if(vval[k] >= v )
		 return;
	 else{
	    vval[k] = v; 
	 }
     v += val[k];
	 val[k] = 0 ; 
	 for(int i = 0 ;i < mp[k].size();i ++)
	 {
	   int nx = mp[k][i].nx ;
	   int vv = mp[k][i].val;
	   dfs(nx,v-vv);
	 }
}
int main(){
    int n;
	scanf("%d",&n);
	for(int i = 0 ;i < n ;i ++)
		scanf("%d",&val[i]);
	printf("***\n");
	int ta,tb,v; 
	while(scanf("%d %d %d",&ta,&tb,&v) != EOF)
	{
		mp[ta].push_back(node(tb,v));
		mp[tb].push_back(node(ta,v));
	}
	for(int i = 0;i <= 10 ;i ++)
			vval[i] = -1e9; 
	dfs(6,0);
	for(int i = 0 ;i <= 6 ;i ++)
		printf("%d ",vval[i]);
return 0;
}
