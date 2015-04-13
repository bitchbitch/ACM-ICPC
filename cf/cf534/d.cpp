// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 01时30分17秒

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
#include<queue>
#define LL long long

using namespace std;
int n ;
int a[200005];
int hs[200005];
int ans[200005];
queue<int> qu[200000];
int ok = 0;
void find(int k,int p)
{
     if(p == 0)
	 {
		if(a[ans[1]] != 0)
			return;
		ok = 1;
        return ;
	 }
	//printf("%d %d\n",k,p);
	if(k >= 2 && hs[k-1] != hs[k] && hs[k-2] == hs[k])
	{
	   find(k-2,p);
	}
	else if(!qu[k].empty())
	 {
         ans[p] = qu[k].front();
		 qu[k].pop();
		 if(hs[k] ==  0)
			 return;
		 hs[k] -- ; 

		if(k != 0 && (hs[k-1] == hs[k]+1 || hs[k+2] == 0 ))
			 find(k-1,p-1);
		 else find(k+2,p-1);
	 }
}
int main(){
	scanf("%d",&n);
	ok = 0;
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		hs[a[i]] ++ ; 
		qu[a[i]].push(i);
	}
	int site = 0 ; 
	int mx =0 ; 
	for(int i = 0;i <= n;i ++)
	{
         if( hs[i] >= mx ) 
		 {
			site = i ; 
			mx = hs[i];
		 }
	}
	find(site,n);
	if(ok)
	{
	   printf("Possible\n");
	   for(int i = 1;i <= n;i ++)
		   printf("%d ",ans[i]);
	   printf("\n");
	}
	else printf("Impossible\n");
return 0;
}
