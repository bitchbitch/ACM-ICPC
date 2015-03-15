// File Name: CrossingRivers.cpp
// Author: darkdream
// Created Time: 2013年11月26日 星期二 21时48分51秒

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
struct node{
  int p , l , v; 
}hehe[10000];
int cmp(const void * a ,const void *b)
{
   return (*(node*)a).p -(*(node*)b).p;
}
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout); 
   int n ,d;
   int t = 0;
   while(scanf("%d %d",&n,&d),n||d)
   {
     double ans = 0  ;
	 t ++;
	 for(int  i = 1;i <= n;i ++)
	 {
	   scanf("%d %d %d",&hehe[i].p,&hehe[i].l,&hehe[i].v);
	 }
	 qsort(hehe+1,n,sizeof(node),cmp);
     int p = 0 ;
	 for(int i = 1;i <= n;i ++)
	 {
		ans += hehe[i].p - p;

	    ans += hehe[i].l*2.0/hehe[i].v;
        p = hehe[i].p + hehe[i].l ;
	 }
	 ans += d - p ;
     printf("Case %d: %.3lf\n\n",t,ans);
   }	
return 0;
}
