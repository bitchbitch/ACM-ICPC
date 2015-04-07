// File Name: xxbhx.cpp
// Author: darkdream
// Created Time: 2015年04月07日 星期二 12时32分57秒

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
map<int,int> mp;
int a[4100000] ;
int b[4100000];
void solve(int la,int ra,int lb,int rb)
{
    if(rb - lb == 2)
	{
       printf("%d %d %d ",b[lb],b[rb],b[lb+1]);
	   return ;
	}
	int x = mp[a[la+1]];
	solve(la+1,la+(x-lb)+1,lb,x);
	printf("%d ",a[la]);
	solve(la+(x-lb)+2,ra,x+1,rb-1);

}
int main(){
   int n ;
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
	   scanf("%d",&a[i]);
   for(int i = 1;i <= n;i ++)
   {
	   scanf("%d",&b[i]);
	   mp[b[i]] = i; 
   }
   solve(1,n,1,n);
return 0;
}
