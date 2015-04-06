// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年04月05日 星期日 14时55分31秒

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
#define maxn 3000005
using namespace std;
int n , q; 
int a[maxn];
int from[maxn];
int tans ;
int pp;
int read_int() {
    char ch = getchar();
    while (!isdigit(ch)) {
        ch = getchar();
    }
    int ret = 0;
    while (isdigit(ch)) {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}
int main(){
//	freopen("input","r",stdin);
    scanf("%d %d",&n,&q);
	for(int i = 1;i <= n;i ++)
	{	
		a[i] = read_int();
	    a[i+n] = a[i];
	}
	while(q--)
	{
       LL lim;
	   cin >>lim;
	   LL tsum =0 ; 
	   int ans = 1e9 ;
	   int milr = 1e9 ; 
	   int l ,r ; 
	   l = 2*n;
	   r = 2*n-1;
	   int j = 1; 
	   for(int i = 1;i <= 2* n ;++i)
	   {
		   tsum += a[i];
	       while(tsum > lim )
		   {
		       tsum -= a[j];
			   j ++;
		   }
		   from[i] = j-1;
		   if(i - (j-1)< milr && i >= n)
		   {
		      l = j-1;
			  r = i ; 
			  milr = (i-(j-1));
		   }
	   }
	   for(int i = n+1;i <= 2* n;i ++)
			from[i+n] = from[i]+n;
	   if(l < n)
	   {
	     l += n ; 
		 r += n ; 
	   }
	   //printf("%d %d\n",l,r);
	   for(pp = l;pp <= r;pp++)
	   {
		   tans = 0 ; 
		   for(int i = pp ;i >= 0;i = from[i])
		   {
			   tans ++ ; 
		       if(i <= pp -n)
			   {
				   break;
			   }
		   }
		   ans = min(ans,tans-1);
	   }
	  printf("%d\n",ans);
	
	}
	

return 0;
}
