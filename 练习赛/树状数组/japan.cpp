// File Name: japan.cpp
// Author: darkdream
// Created Time: 2013年03月27日 星期三 17时24分43秒

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

using namespace std;
struct point
{
  int x, y ;
  bool operator < (const point& t) const {
     if(y == t.y)
		 return x < t.x;
	 else
		 return y < t.y;
		 
  }
};
struct point kiss[1000005];
int a[1005];
int lowbit(int x)
{
  return x&(-x);
}
int sum (int x)
{
   x = 1001 -x;
   int res = 0 ;
   while(x >= 1)
   { 
	   res += a[x];
	   x -= lowbit(x);
   }
  return res;
}
void update(int x)
{
  x = 1001 -x;
  while(x <= 1001)
  {
      a[x]++;
	  x += lowbit(x);
  }
}
int main(){
	//freopen("/home/plac/problem/input.txt","r",stdin);
	
	int t ;
	scanf("%d",&t);
	for(int k = 1; k <= t; k ++)
	{
		memset(a,0,sizeof(a));
		memset(kiss,0,sizeof(kiss));
	    int n, m, s ;
		scanf("%d %d %d",&n,&m,&s);
		for(int i = 0; i < s ; i++)
		  scanf("%d %d",&kiss[i].x,&kiss[i].y);
		sort(kiss,kiss+s);
		//printf("*********\n");
        //for(int i =0 ;i < s ;i ++)
	//		printf("%d %d\n",kiss[i].x,kiss[i].y);
		__int64 SUM = 0 ;
		for(int i = 0 ;i <s ;i ++)
		{
		 // printf("%d\n",sum(kiss[i].x+1));
           SUM += sum(kiss[i].x+1);
		   update(kiss[i].x);
		}
		printf("Test case %d: %I64d\n",k,SUM);
	}
return 0;
}
