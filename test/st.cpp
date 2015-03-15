// File Name: st.cpp
// Author: darkdream
// Created Time: 2014年07月31日 星期四 20时45分03秒

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
#define maxn 2000005
int M = 0 ;
int L(int x)
{
   return 2 * x; 
}
int R(int x)
{
  return 2  * x + 1; 
}
void build(int c ,int l , int r)
{
   if(l == r)
   {
       if(c > M)
		   M = c; 
	   return ;
   }
   int m = (l+r)/2;
   build(L(c),l,m);
   build(R(c),m+1,r);
}
int main(){
   double  maxdouble = 0 ; 
   for(int i =1 ;i <= 200000;i ++)
   {
      M = 0 ; 
	  build(1,1,i);
	  if(M*1.0/i > maxdouble )
		  maxdouble  = M*1.0/i;
	  if(i % 10000 == 0 )
		  printf("节点数目：%6d 树节点倍数:%lf\n",i,maxdouble);
   }
  printf("%lf\n",maxdouble);
return 0;
}
