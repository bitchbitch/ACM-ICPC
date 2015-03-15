// File Name: a.cpp
// Author: darkdream
// Created Time: 2013年11月26日 星期二 23时28分12秒

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

int ans[1000];
int cmp(const void *a , const void * b)
{
   return *(int *)a -*(int*)b;
}
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
   int n , d; 
   scanf("%d %d",&n,&d);
   ans[0] = 0 ;
   for(int i =1;i <= n;i ++)
   {
      scanf("%d",&ans[i]);
   }
   qsort(ans+1,n,sizeof(int),cmp);
   for(int i = 2 ;i <= n;i ++)
   {
     ans[i] += ans[i-1];
   }
   int m ;
   scanf("%d",&m);
   if(m <= n)
	   printf("%d\n",ans[m]);
   else printf("%d\n",ans[n] - (m-n)*d);

return 0;
}
