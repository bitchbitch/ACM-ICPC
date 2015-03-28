// File Name: h.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 16时28分10秒

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
int t;
struct node{
  int l , r ;
  bool operator<(node a,node b)
  {
	  return a.l < b.l ;
  }
}
int main(){
    scanf("%d",&t);
	while(t--)
	{
       int n ;
	   scanf("%d",&n);
	   int op,v;
	   for(int i = 1; i<= n ;i ++)
	   {
	      scanf("%d",&op);
		  if(op == 1)
		  {  	 
      
		  }
	   }
	}
return 0;
}
