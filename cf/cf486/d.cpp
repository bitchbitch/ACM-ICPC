// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年11月12日 星期三 19时23分45秒

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
#define maxn 100005 
using namespace std;
int F1[maxn];
int F2[maxn];
int a[maxn];
int vis[maxn];
vector<int> LIS;
int L;
int find(int x)
{
   int l = 0; 
   int r = LIS.size() - 1;
   int m; 
   while(l <= r )
   {
      m = (l + r) >>  1; 
	 if(x < LIS[m])
	 {
         l = m  + 1; 	 
	 }else r = m - 1;
   }
   //printf("%d %d %d %d\n",l,m,a[m],x);
   return l; 
}
int main(){
     int n; 
	 scanf("%d",&n);
	 for(int i = 1;i <= n;i ++)
	 {
		scanf("%d",&a[i]);
        int p = upper_bound(LIS.begin(),LIS.end(),a[i]-1) - LIS.begin();
		if(p == LIS.size())
		{
		   LIS.push_back(a[i]);
		}else{
		   LIS[p] = a[i];
		}
		F1[i] = p + 1;  
	 }
	 L = LIS.size();
	 //printf("%d\n",L);
	 LIS.clear();
	 for(int i = n;i >= 1;i --) 
	 {
	    int p = find(a[i]);
		if(p == LIS.size())
			LIS.push_back(a[i]);
		else LIS[p] = a[i];
		F2[i] = p+1;
		//printf("%d %d\n",i,F2[i]);
	 }
/*	 for(int i = 1;i <= n;i ++)
		 printf("%d*",F1[i]);
	 printf("\n");
*/	 memset(vis,0,sizeof(vis));
	 for(int i = 1;i <= n;i ++)
	 {
		// printf("%d ",F2[i]);
	   if(F1[i] + F2[i] -1== L)
		   vis[F2[i]] ++ ; 
	 }
	 /*for(int i = 1;i <= n;i ++)
		 printf("%d ",vis[i]);
	 printf("\n");*/
	 //printf("\n");
	 for(int i = 1;i <= n;i ++)
	 {
	   if(F1[i] + F2[i] -1 < L)
	      printf("1");
	   else if(vis[F2[i]] == 1)
		   printf("3");
	   else printf("2");
	 }
    
return 0;
}
