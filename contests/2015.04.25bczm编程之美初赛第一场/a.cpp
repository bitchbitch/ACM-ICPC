// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月25日 星期六 14时14分13秒

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
int fa[100005];
int col[100005];
vector<int>  mp[100005];
map<int,int> ans[100005];
void dfs(int k ,int la)
{
	for(int i = 0 ;i < mp[k].size() ;i ++)
	{
		if(mp[k][i] == la)
			continue;
		fa[mp[k][i] ] = k ; ; 
		ans[k][0] ++ ; 
		dfs(mp[k][i],k);
	}
}
int n; 
int main(){
	int T; 
	scanf("%d",&T);
	for(int ca = 1; ca <= T;ca ++){
       scanf("%d",&n);
	   for(int i = 0;i <= n;i ++)
	   {
		   mp[i].clear();
		   ans[i].clear();
	   }
	   int ta,tb;
	   for(int i = 1;i < n;i ++){
		 scanf("%d %d",&ta,&tb);	 
		 mp[ta].push_back(tb);
		 mp[tb].push_back(ta);
	   }		   
	   ans[0][0] = 1 ;
	   dfs(1,0);

	   printf("Case #%d:\n",ca);
	   int q; 
	   scanf("%d",&q);
	   memset(col,0,sizeof(col));
	   int st;
	   int sum = 1; 
	   for(int i = 1;i <= q;i ++){
		   scanf("%d",&st);
		   if(st == 2 ){
				scanf("%d %d",&ta,&tb);
				if(col[ta] != tb){
					sum += ans[ta][col[ta]];
					sum -= (ans[ta][tb]);
					if(ta != 1)
					{
					if(col[ta] == col[fa[ta]])
					{
						sum ++ ; 
					}else{
						if(tb == col[fa[ta]]){
							sum --;	
						}
					}
					ans[fa[ta]][col[ta]] -- ; 
					ans[fa[ta]][tb] ++ ; 
					}
					col[ta] = tb; 
				}
		   }else{
			   printf("%d\n",sum);
		   }
	   }
	}

return 0;
}
