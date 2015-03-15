// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年11月12日 星期三 00时35分31秒

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
  int v, p ;
  node(int _v ,int _p)
  {
    v = _v;
	p = _p;
  }
};
int len = 0 ; 
vector<int>LI;
vector<node> LIS[100005];
int ans[100005];
int np[100005];
int n;
void solve()
{
   for(int i = 0;i < len - 1; i ++)
   {
      int k = LIS[i].size();
	  if(k == 1)
	  {
	     ans[LIS[i][0].p] = 2; 
	  }
   }
   int num = LIS[len-1].size();
   if(num == 1 )
   {
	     ans[LIS[len-1][0].p] = 2; 
   }else{
     for(int i = 0 ;i < num;i ++)
	 {
	     ans[LIS[i][0].p] = 1; 
	 }
   }
   int be = 0;
   int en = num -1;
   for(int i = len - 2;i >= 1;i --)
   {
       int num = LIS[i].size(); 
       int tbe = -1 ; 
	   int ten = -1;
	   int j = 0; 
	   int s = be; 
	   {
		  node tmp = LIS[i][j];
		  if(tmp.v < LIS[i+1][s].v && tmp.p < LIS[i+1][s].p)
		  {
		     if(tbe == -1)
			 {
			    tbe = j ; 
			 }
			 ten = j; 
		  }else if(tmp.v > LIS[i+1][s].v){
		      
		  }
	   }
	   be = tbe;
	   en = ten;
	   if(be == en)
	   {
	       ans[LIS[i][be].p] = 2; 
	   }else
	     for(int j= be;j <= en;j ++)
		 {
		    ans[LIS[i][j].p] = 1; 
		 }
	    
   }
}
int main(){
   int n;
   scanf("%d",&n);
   len = 0 ; 
   for(int i = 1;i <= n;i ++)
   {
      int t; 
      scanf("%d",&t);
	  int p = upper_bound(LI.begin(),LI.end(),t) - LI.begin();
      if(p == LI.size())
	  {
		  LI.push_back(t);
		  len ++;
	  }
	  else LI[p] = t;
	  np[x] = LI[p+1].size() - 1;
	  LIS[p].push_back(node(t,i));
   }
   solve();
   for(int i =1;i <= n;i ++)
	   printf("%d",ans[i]+1);
return 0;
}
