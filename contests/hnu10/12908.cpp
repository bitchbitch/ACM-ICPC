// File Name: 12908.cpp
// Author: darkdream
// Created Time: 2014年08月17日 星期日 15时26分28秒

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
int a[100005];
int b[100005];
int cmp(int x , int y)
{
  return x < y ; 
}
int main(){
   int n ,m ; 
   while(scanf("%d %d",&n,&m) != EOF)
   {
      for(int i = 1;i <= n;i ++)
		  scanf("%d",&a[i]);
	   for(int j = 1;j <= m ;j ++)
			  scanf("%d",&b[i]);
	   int max = 0 ;
	   sort(a+1,a+1+n,cmp);
	   sort(b+1,b+1+m,cmp);
	   for(int i = 1;i <= n;i ++)
	   {
	      
	   }
   }
    
return 0;
}
