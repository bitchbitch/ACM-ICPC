// File Name: h.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 14时17分50秒

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
int t ; 
int n; 
int num[200];
int sum[200];
int ans[4];
int tmp[4];
double mx = 1e9 ; 
double pin;
void dfs(int k,double val,int step)
{
	if(step == 3)
	{
	   val += fabs(sum[160] - sum[k] - pin);
	   if(val < mx-(1e-8))
	   {
		   memcpy(ans,tmp,sizeof(tmp));
		   mx = val;
	   }
	   return ;
	}
    for(int j = k+1;j < 160 ;j ++)	
	{
	  tmp[step+1] = j;
	  dfs(j,val + fabs(sum[j]- sum[k] - pin),step + 1);
	}
}
int main(){
	scanf("%d",&t);
	for(int CA = 1; CA <= t ; CA ++)
	{
	   scanf("%d",&n);
	   int k ; 
	   int tp ; 
	   mx = 1e9 ;
	   memset(num,0,sizeof(num));
	   memset(sum,0,sizeof(sum));
	   for(int i = 1;i <= n;i ++)
	   {
           scanf("%d",&tp); 
		   num[tp] ++ ;
	   }
	   sum[0] = num[0];
	   for(int i = 1;i <= 160;i ++)
		   sum[i] = sum[i-1] + num[i];
	   pin = n*1.0/4;

	   for(int i= 0;i < 160; i ++)
	   {
		tmp[1] = i; 
	    dfs(i,fabs(sum[i]-pin),1);
	   }
	   printf("Case %d:",CA);
	   for(int i= 1;i <= 3;i ++)
		   printf(" %d",ans[i]);
	   printf("\n");
	}
return 0;
}
