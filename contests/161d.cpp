// File Name: 161d.cpp
// Author: darkdream
// Created Time: 2014年07月26日 星期六 17时28分39秒

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
int n, k ; 
vector<int> m[50005];
LL sum = 0 ; 
int bfs(int v)
{

}
int main(){
   int n ,k ;
   scanf("%d %d",&n,&k);
   for(int i =1 ;i < n;i ++)
   {
     int a, b ; 
	 scanf("%d %d",&a,&b);
     m[a].push_back(b);
	 m[b].push_back(a);
   } 
   bfs(1);
return 0;
}
