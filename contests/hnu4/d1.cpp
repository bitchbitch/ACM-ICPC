// File Name: d1.cpp
// Author: darkdream
// Created Time: 2014年07月27日 星期日 16时51分17秒

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
int a[1000000];
int main(){
   int n , m; 
   while(scanf("%d %d",&n,&m) != EOF)
   {
        for(int i =1 ;i <= n;i ++)
		{
		     scanf("%d",&a[i]);
		}
		for(int i = 1;i <= m ;i ++)
		{
		   int x, y , z; 
		   scanf("%d %d %d",&x,&y,&z);
		   a[x] = min(a[x],a[y]+a[z]);
		}
		printf("%d\n",a[1]);
   }
return 0;
}
