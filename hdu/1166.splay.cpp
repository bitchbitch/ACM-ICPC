// File Name: 1166.splay.cpp
// Author: darkdream
// Created Time: 2015年04月02日 星期四 17时08分14秒

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
const int maxn = 50005
int t ; 
int a[maxn];
struct SplayTree{
     int sz[maxn];
	 int ch[maxn][2];
	 int pre[maxn];
	 int root,top1,top2;
     int ss[maxn],que[maxn];
	 inline void Rotate(int x,int f){
	     int y = pre[x];
		 push_down(y);
		 push_down(x);
	 }
}
int main(){
  scanf("%d",&t);
  while(t--)
  {
     int n ;
	 scanf("%d",&n);
	 for(int i = 1;i <= n;i ++)
	 {
           
	 }
  }
return 0;
}
