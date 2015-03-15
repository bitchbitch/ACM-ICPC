// File Name: 1009.cpp
// Author: darkdream
// Created Time: 2014年08月19日 星期二 12时16分48秒

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
int num[10];
int mxsco[] = {100,84,79,74,69};
int misco[] = {85,80,75,70,60};
double sc[] = {4.0,3.5,3.0,2.5,2.0};
int sco,n,lsco;
double ansmi,ansmx;
void dfs(int k , int lnum,int mx,int mi,double tsc)
{
	//printf("%d %d\n",mx,mi);
	if(k == 5 )
	{
	   //printf("%d %d\n",mx,mi);
	   if(lsco <= mx && lsco >= mi && lnum == 0 )
	   {
	     if(tsc < ansmi)
			 ansmi = tsc;
		 if(tsc > ansmx)
		 {
	        /* printf("%d %d\n",mx,mi);
			 for(int i = 0;i < 5;i ++)
				 printf("%d ",num[i]);
			 printf("\n");*/
			 ansmx = tsc;
		 }
	   }
	   return;
	}
	if(lsco < mi)
		return;
    for(int i = 0 ;i <= lnum ;i ++)
	{
		num[k] = i ; 
        dfs(k+1,lnum-i,mx+i*mxsco[k],mi+i*misco[k], tsc+i*sc[k]);	   
	}
}
int main(){
   int T;
   scanf("%d",&T);
   while(T--)
   {
     scanf("%d %d",&sco,&n);
	 lsco = sco*n;
	 ansmi = 1e10;
	 ansmx = -1e10;
	 dfs(0,n,0,0,0.0);
	 printf("%.4lf %.4lf\n",ansmi/n,ansmx/n);
   }
return 0;
}
