// File Name: j.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 15时35分41秒

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
#define maxn 100005
using namespace std;
int t ;
int n;
struct node{
  unsigned LL val ,num;
}a[maxn];
unsigned LL ans ,ansnum;
bool cmp(node a, node b)
{
   return a.val < b.val;
}
int main(){
//	freopen("input","r",stdin);
//	freopen("output","w",stdout);

    scanf("%d",&t);
	for(int CA = 1;CA <= t ; CA++)
	{
	   scanf("%d",&n);
	   for(int i =1 ;i <= n ;i ++)
	   {
	      scanf("%llu %llu",&a[i].val,&a[i].num);
	   }
	   sort(a+1,a+1+n,cmp);
	   unsigned LL tsum =0 ; 
	   ans =  0 ;
	   ansnum = 1; 
	   for(int i = 1;i <= n;i ++)
	   {
		   tsum += a[i].num;
	       ans = (ans + a[i].num * tsum); 
		   if(i != 1)
			   ansnum = ansnum *(a[n-i+1].num+1) % M;
	   }
	   printf("Case %d: %llu %llu\n",CA,ans,ansnum);
	}

return 0;
}
