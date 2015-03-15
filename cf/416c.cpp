// File Name: 416c.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 15时00分48秒

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
struct node{
  int x, y, si,an; 
}re[1005];
int cmp(node a ,node b)
{
   if(a.y == b.y)
	   return a.x > b.x;
   return a.y > b.y;
}
int cmp1(node a, node b)
{
    return a.si < b.si;
}
struct table{
 int ta,si; 
}ta[1005];
int cmp2(table a, table b)
{
   return a.ta < b.ta;
}
int hs[1005];
int main(){
  int n,m; 
  scanf("%d",&n);
  for(int i =1 ;i <= n;i ++)
  {
     scanf("%d %d",&re[i].x, &re[i].y);
     re[i].si = i ; 
  }
  scanf("%d",&m);
  for(int i = 1;i <= m;i ++)
  {
	  scanf("%d",&ta[i].ta);
      ta[i].si = i ; 
  }
  sort(ta+1,ta+1+m,cmp2);
  sort(re+1,re+n+1,cmp);
  int s = 0 ; 
  int sum = 0 ; 
  for(int i = 1;i <= n;i ++)
  {
    for(int j = 1;j <= m;j ++)
	{
	  if(hs[j] == 0 && ta[j].ta >= re[i].x)
	  {
	    re[i].an = ta[j].si; 
		hs[j] = 1;
		s ++ ; 
		sum += re[i].y;
	    break;
	  }
	}
  }
  printf("%d %d\n",s,sum);
  sort(re+1,re+1+n,cmp1);
  for(int i = 1;i <= n;i ++)
  {
    if(re[i].an != 0 )
		printf("%d %d\n",i,re[i].an);
  }
  

return 0;
}
