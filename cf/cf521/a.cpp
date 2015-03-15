// File Name: a.cMM
// Author: darkdream
// Created Time: 2015年03月02日 星期一 14时59分12秒

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
#define M 1000000007
using namespace std;
LL quick_mod(LL a, LL b)
{
	LL ans = 1;
	a %= M;
	while(b)
	{
		if(b & 1)
		{
			ans = ans * a % M;
			b--;
		}
		b >>= 1;
		a = a * a % M;
	}
	return ans;
}

LL C(LL n, LL m)
{
	if(m > n) return 0;
	LL ans = 1;
	for(int i=1; i<=m; i++)
	{
		LL a = (n + i - m) % M;
		LL b = i % M;
		ans = ans * (a * quick_mod(b, M-2) % M) % M;
	}
	return ans;
}

LL Lu(LL n, LL m)
{
	if(m == 0) return 1;
	if(n < m )
	  swap(n,m);
	return C(n % M, m % M) * Lu(n / M, m / M) % M;
}
LL P(int n , int p)
{
  if(p ==  1)
	  return n;  
  LL x = P(n,p/2);
  if( p % 2 == 0 )
  {
     return x*x % M;
  }else{
    return ((x*x)%M)*n%M;
  }
}
int a[100005];
int ans[10][100005];
LL P(int x)
{
   if(x == 1 )
	   return 1 ; 
   if(x == 2)
	   return 10;
   LL tmp = P(x/2);
   if(x % 2 == 0)
	   return x*x % M;
   else return ((x*x)%M)*10%M;
}
int main(){
	int n , k;
	scanf("%d %d",&n,&k);
    LL sum = 0 ;
	LL tmp = Lu(n-1,k-1);
	int mx = n-k;
	for(int i = 1;i <=n-mx;i ++)
	{
       scanf("%1d",&a[i]);	
	   if(a[i] != 0 )
	   {
	      ans[a[i]][min(n-i+1,mx)] ++;
		  //printf("%d\n",min(n-i+1,mx));
	   }
	}
    for(int i = 1;i <= 9 ;i ++)
	{
	  for(int j = 100000;j >= 1;j --)
	  {
	    ans[i][j] += ans[i][j+1];
	    if(ans[i][j] != 0)
		{
		sum = (sum + (( * ans[i][j])%M * i%M)*P(j))%M; 
		 printf("%d %d %lld\n",i,j,sum);
		}
	  }
	}
	printf("%lld\n",sum);
	return 0;
}
