// File Name: cows.cpp
// Author: darkdream
// Created Time: 2014年04月25日 星期五 12时55分42秒

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

using namespace std;
struct node{
  int x, y,num;
}a[200005];
int ans[200005];
int sum[200005];
bool cmp(node a, node b)
{
   if(a.x == b.x)
	   return a.y > b.y; 
    return a.x < b.x;
}
int lowbit(int x)
{
  return x & (-x);
}
int getsum(int k )
{
   int tsum = 0 ;
   while(k >= 1)
   {
      tsum += sum[k] ;
	  k -= lowbit(k);
   }
   return tsum ; 
}
void update(int k,int x)
{
   while(k <= 100004)
   {
        sum[k] += x; 
		k += lowbit(k);
   }
}
int main(){
   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n;  
  while(scanf("%d",&n) != EOF)
   {
        if(n == 0 )
			break;
		memset(ans,0,sizeof(ans));
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		for(int i = 0;i < n;i ++)
		{
	       scanf("%d %d",&a[i].x,&a[i].y);
		   a[i].y ++ ; 
		   a[i].num = i ; 
		}
	    sort(a,a+n,cmp);
		int up = 1 ; 
		for(int i = 0 ;i < n;i ++)
		{
	       if( i != n - 1 && a[i].x == a[i+1].x && a[i].y == a[i+1].y)
		   {
		       up ++ ; 
			   ans[a[i].num] =  getsum(100003) - getsum(a[i].y -1); 
		   }
		   else {
			   ans[a[i].num] =  getsum(100003) - getsum(a[i].y- 1); 
		       update(a[i].y , up);
			   up = 1; 
		   }
		}
		for(int i = 0;i < n;i ++)
		   printf(i == 0 ?"%d":" %d",ans[i]);
		printf("\n");
   }
return 0;
}
