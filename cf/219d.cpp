// File Name: 219d.cpp
// Author: darkdream
// Created Time: 2015年03月10日 星期二 19时26分38秒

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
#define maxn 200006
using namespace std;
map <int,int> mp[maxn];
vector<int>  dmp[maxn]; 
int n ;
int dpx[maxn];
int dfs(int k ,int la )
{
   for(int i = 0 ;i < dmp[k].size();i ++)
   {
		if(dmp[k][i] == la)
			 continue;
        if(mp[k][dmp[k][i]] == 0)
			dpx[k] ++ ;
		dpx[k] += dfs(dmp[k][i],k);
   }
   return dpx[k];

}
void dfs2(int k ,int s,int la)
{
   dpx[k] += s; 
   for(int i = 0 ;i < dmp[k].size() ;i ++)
	{
		 if(dmp[k][i] == la)
			 continue;
	     int tmp = dpx[k] - dpx[dmp[k][i]];
		 if(mp[k][dmp[k][i]] == 1)
			 tmp ++ ;
		 else tmp -- ;
	     dfs2(dmp[k][i],tmp,k) ;
	}
}
int main(){
	 scanf("%d",&n);
     memset(dpx,0,sizeof(dpx));
	 for(int i = 1 ;i < n;i ++)
	 {
         int ta, tb; 
		 scanf("%d %d",&ta,&tb);
		 dmp[ta].push_back(tb);
		 dmp[tb].push_back(ta);
		 mp[ta][tb] = 1; 
	 }
	 dfs(1,0);
	 dfs2(1,0,0);
	 int mi = 1e9 ; 
	 for(int i = 1;i <= n;i ++)
	 {
	    mi = min(mi,dpx[i]);
		//printf("%d ",dpx[i]);
	 }
	 printf("%d\n",mi);
	 for(int i = 1;i <= n;i ++)
		 if(dpx[i] == mi)
			 printf("%d ",i);
return 0;
}
