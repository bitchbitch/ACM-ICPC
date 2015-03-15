// File Name: poj3468.sz.cpp
// Author: darkdream
// Created Time: 2014年11月07日 星期五 08时45分48秒
#include<limits.h>
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
#define maxn 1000010
using namespace std;
#define valtree ch[ch[root][1]][0]
struct SplayTree{
     int ch[maxn][2];
	 int pre[maxn];
	 int root ; 
	 int top1;
	inline void Rotate(int x ,int f){
       int y = pre[x];
	   ch[y][!f] = ch[x][f]; 
	   pre[ch[x][f]] = y ; 
	   pre[x] = pre[y];
	   if(pre[x])
		   ch[pre[y]][ch[pre[y]][1] == y] = x; 
	   ch[x][f] = y ; 
	   pre[y] = x; 
   }
   void Splay(int x, int goal){
	  while(pre[x] != goal){
	     if(pre[pre[x]] == goal){
		    Rotate(x,ch[pre[x]][0] == x);
		 }else{
		    int y = pre[x],z = pre[y];
			int f = (ch[z][0] == y);
			if(ch[y][f] == x)
			{
			    Rotate(x,!f),Rotate(x,f);
			}else{
			    Rotate(y,f),Rotate(x,f);
			}
		 }
	  }
	  if(goal == 0 ) root = x; 
   }
   int ABS(int x)
   {
      if(x < 0)
		  return -x;
	  return x ;
   }
   int  Rotateto(int k ,int goal)
   {
       int r = root ;
	   int mi = INT_MAX;
       while(1)
	   {
	     mi = min(mi,ABS(val[r]-k));
		 if(!ch[r][val[r] < k])
			 break;
		 r = ch[r][val[r] < k ];
	   }
	   int &tt = ch[r][val[r] < k];
	   newnode(tt,k);
	   pre[tt] = r; 
	   Splay(tt,0);
	   return mi;
   }
   /*void erase(int x ){
       int father = pre[x];
	   int head = 0 , tail = 0 ; 
	   for()
	   }*/
   /*void debug(){printf("%d\n",root);Treaval(root);}
   void Treaval(int x) {
	   if(x) {
		   Treaval(ch[x][0]);
		   printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d sum = %3lld\n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x],sum[x]);
		   Treaval(ch[x][1]);
	   }
   }*/
   void newnode(int &x,int c)
   {
      x = ++ top1;
	  ch[x][0] = ch[x][1] = pre[x] = 0 ; 
      val[x] = c; 	
   }
   void init(int v)
   {
       ch[0][0] = ch[0][1] = pre[0] =0 ; 
	   root = top1 = 0 ; 
	   newnode(root,v); //这里注意 root 是从1 开始的
   }
   int val[maxn];
}sp; 
int main(){
   int n ; 
   scanf("%d",&n);
   if(n == 0 )
   {
     printf("%d\n",0);
	 return 0;
   }
   int v; 
   scanf("%d",&v);
   sp.init(v);
   int ans = v;
   for(int i = 1;i < n;i ++)
   {
	 if(scanf("%d",&v) == EOF)
		 v = 0 ; 
	 ans += sp.Rotateto(v,0);
   }
   printf("%d\n",ans);
return 0;
}
