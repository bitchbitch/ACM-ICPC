// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年07月12日 星期六 10时44分56秒

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
#include<climits>
#include<queue>

using namespace std;
long long n , m , a;
int log10(long long n ,long long a)
{
	double t = (log(a)/log(n));
	return   (t+1.0 - 1e-8);

}
long long P(long long x)
{
  long long ans = 1; 
  for(int i =1 ;i <= x ;i ++)
	  ans *= 2 ; 
  return ans ; 
}
int dfs(long long  n,long long  m )
{
	if(n != 1)
	{
		double t = (log(a)/log(n));
		long long  k = (t+1.0 - 1e-8);
		if(k <= m )
		{
			return 1;
		}
	} 
	int t1;
	int t2; 
	if(m == 1 && n*n >= a )
	{
		t1 = 1; 
		t2 = (a - n )%2;
	}
	else if(n == 1 &&  P(m) >= a)
	{
	    t1 = 1;
		t2 = dfs(n+1,m);
	}else{
		t1 = dfs(n+1,m);
		t2 = dfs(n,m+1);
	}
	if(t1 && t2)
		return 0 ;
	if(!t1 && !t2)
		return 1;
	return 1;
}
int main(){
//	   freopen("cin.txt","r",stdin);
//	  freopen("cout1.txt","w",stdout);

	while(scanf("%lld %lld %lld",&n,&m,&a) != EOF)
	{
		if(n == 1)
		{
			if(log10(n+1,a) <= m)
			{	  printf("draw\n");
			   continue;
			}
			int t1 = dfs(n,m);
		}
		if(n!= 1)
			if(log10(n,a) <= m)
			{ 
				printf("lose\n");
				continue;
			}
		int t = dfs(n,m);
		if(t == 1 )
			printf("win\n");
		else printf("lose\n");
	}
	return 0;
}
