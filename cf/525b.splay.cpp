// File Name: 525b.splay.cpp
// Author: darkdream
// Created Time: 2015年04月01日 星期三 19时29分23秒

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
struct SplayTree{
     int sz[maxn];
	 int ch[maxn][2];
	 int pre[maxn];
	 int root ,top1,top2;
	 int ss[maxn],que[maxn];
	 inline void Rotate(int x ,int f){
	      int y = pre[x];
		  push_down(y);
		  push_down(x);
		  ch[y][!f] = ch[x][f];
		  pre[ch[x][f]] = y ; 
		  pre[x] = pre[y];
		  if(pre[x])  ch[pre[y]][ch[pre[y]][1] == y] = x; 
		  ch[x][f] = y ; 
		  pre[y] = x; 
		  push_up(y);
	 }
	 inline void Splay(int x, int goal){
	       push_down(x);
		   while(sz[ch[x][0] != k]){
		   
		   }
	 }
}
int main(){
 
return 0;
}
