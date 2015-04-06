// File Name: cf448c.cpp
// Author: darkdream
// Created Time: 2015年04月06日 星期一 22时26分11秒

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
#define maxn 5005
using namespace std;
int a[maxn];
LL solve(int l ,int r ,int k)
{
	if(r < l )
		return 0 ;  
	if(l == r)
	{
	   return 1; 
	}
	LL mi = r-l + 1 ; 
	LL minum = a[l];
    for(int i = l;i <= r; i ++)
	{
        if(a[i] < minum)
			minum = a[i];
	}
	int len  =0 ; 
	LL tt = minum - k ; 
	for(int i = l ;i <= r;i ++)
	{
        if(a[i] >minum)
		{
	       len ++; 	
		}else{
		   tt += solve(i-len,i-1,minum) ;
		   len = 0 ; 
		}
	}
	if(len)
	  tt += solve(r-len+1,r,minum);
	//printf("%d %d %lld %lld %lld %d\n",l,r,tt,mi,minum,len);
	return min(mi,tt);
}
int n ; 
int main(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i ++)
	  scanf("%d",&a[i]);
  printf("%lld\n",solve(1,n,0)) ;
  return 0;
}
