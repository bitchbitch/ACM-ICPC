// File Name: M.cpp
// Author: darkdream
// Created Time: 2014年05月12日 星期一 15时39分15秒

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
#define  MAXN 3000000
using namespace std;


int hs[MAXN+4];
int num = 0 ; 
int ans[1000005];

void solve()
{
    memset(hs,0,sizeof(hs));
	int x = 1;
    hs[x] = 1; 
	for(int i = 1;i <= MAXN;i ++){
	   if(hs[i]){
	     if(2 * i + 1 <= MAXN  )
			 hs[2*i+1] = 1;
	     if(5*i - 1 <= MAXN)
		 {
		     hs[5*i -1] = 1 ;
		 }
	   }
	}
	for(int i = 1;i <= MAXN; i ++)
		if(hs[i])
		{
		  num ++ ; 
		  ans[num] = i ; 
		}
}
int main(){
   solve(); 
   //printf("%d\n",num);
   //freopen("M.in","r",stdin);
   //freopen("M.out","w",stdout);
   int T;
   scanf("%d",&T);
   while(T--)
   {
     int n ;
	 scanf("%d",&n);
	 printf("%d\n",ans[n]);
   }

return 0;
}
