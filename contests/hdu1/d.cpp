// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年07月22日 星期二 21时29分03秒

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
int n , m;
#define maxn 100000
struct node{
   int l , m ; 
}a[maxn],b[maxn];
bool cmp(const void * a,const void *b)
{
    if(a.m == b.m)
		return a.l > b.l;
	return a.m > b.m;
}
int main(){
  while(scanf("%d %d",&n,&m) != EOF)
	{
        for(int i =1 ;i <= n;i ++)
		{
		   scanf("%d %d",&a[i].m,&a[i].l);
		}
		for(int i =1 ;i <= m;i ++)
			scanf("%d %d",&b[i].m,&b[i].l)
        qsort(b+1,b+1+m,cmp);
                                         
	}
return 0;
}
