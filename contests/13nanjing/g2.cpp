// File Name: g2.cpp
// Author: darkdream
// Created Time: 2014年05月19日 星期一 20时44分12秒

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

#define lson l,m,rt<<1
#define rson m+1,rt<<1|1
#define MAXN 805
int xL,xR,yL,yR,val;
int maxv,minv;
int Max[MAXN << 2][MAXN <<2],Min[MAXN << 2][MAXN << 2];
int N , mat[MAXN][MAXN];
int main(){

	int T ; 
	scanf("%d",&t);
    for(int cas = 1; cas <= T ; cas ++)
	{
	  scanf("%d",&N);
	  for(int i = 1;i <= N ;i ++)
		  for(int j = 1 ; j <= N ;j ++)
            scanf("%d",&mat[i][j]);
	  
	  int q; 
	  scanf("%d",&q);
	  while(q--)
	  {
	      int x, y, l ; 
		  l = (l + 1)/2;
		  xL = max(1,x-l+1),xR = min(N,x+l-1);
		  yL = max(1,y-l+1),yR = min(N,y+l-1);
		  minv = 1 << 30 ;
		  maxv = -minv;
	  }
	
	}
	
	return 0;
}
