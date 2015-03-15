/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-07-27 16:16
 * Filename : d.cpp
 * Description :
 * *********************************************************/
// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年07月27日 星期日 13时07分16秒

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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
int n , m ; 
#define LL long long 
LL a[10005];
struct node{
   int a,b; 
};
vector<node> ans[100005];
int visit[100005];
LL dfs(int k)
{
   if(visit[k])
	   return a[k];
   visit[k] = 1; 
   int len = ans[k].size();
   if(len == 0 )
	   return a[k];
   for(int i = 0 ;i < len ;i ++)
   { 
       int ta = ans[k][i].a; 
	   int tb = ans[k][i].b;
       a[k] = min(dfs(ta)+dfs(tb),a[k]);
   }
   return a[k];
}
int main(){
     while(scanf("%d %d",&n,&m) != EOF)
	 {
		for(int i = 1 ;i <= 10004 ;i ++)
		{	
			ans[i].clear();
		}
        memset(visit,0,sizeof(visit));
	    for(int i =1 ;i <= n;i ++)
		{
		   cin >>a[i] ;
		}
		int z, x, y; 
		for(int i =1 ;i <= m;i ++)
		{
		    scanf("%d %d %d",&z,&x,&y);
			struct node temp;
			temp.a = x;
			temp.b = y; 
			ans[z].push_back(temp);
		}
	    dfs(1);
		cout << a[1] << endl;
	 }
return 0;
}
