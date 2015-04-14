// File Name: g.cpp
// Author: darkdream
// Created Time: 2015年04月14日 星期二 18时09分11秒

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
#include<queue>
#include<ctime>
#define LL long long

using namespace std;
int n , m , y;
map<int,int> mp;
struct node{
   int v;
   int k;
   node(){}
   node(int _v ,int _k)
   {
      v = _v; 
	  k = _k; 
   }
   bool operator < (const node &b) const {
	   double s1 = abs(1.0*k/y - 1.0*(v+1)/m) - abs(1.0*k/y-1.0*v/m);
	   double s2 = abs(1.0*b.k/y - 1.0*(b.v+1)/m) - abs(1.0*b.k/y-1.0*b.v/m);
	   return s1 > s2;
   }
};
priority_queue<node> qu;
int ans[1005];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ta,tb; 
	scanf("%d %d %d",&n,&m,&y);
	int v = m;
	for(int i = 1 ;i <= n;i ++){
		scanf("%d",&ta);	
		tb = m * ta /y;
		qu.push(node(tb,ta));
		v -= tb;
	}
	while(v--){	
		node tmp = qu.top();
		qu.pop();
		tmp.v++;
		qu.push(tmp);
	}
	for(int i= 1;i <= n;i ++)
	{
	 node tmp = qu.top();
	  ans[i] = tmp.v; 
	  qu.pop();
	}
	sort(ans+1,ans+1+n);
	for(int i = 1;i <= n;i ++)
		printf("%d ",ans[i]);
	
return 0;
}
