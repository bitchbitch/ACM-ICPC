// File Name: poj3468.sz.cpp
// Author: darkdream
// Created Time: 2014年11月07日 星期五 08时45分48秒

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
#define maxn 100010
using namespace std;
#define keytree ch[ch[root][1]][0]
struct SplayTree{
   int sz[maxn];   //大小
   int ch[maxn][2];  //儿子
   int pre[maxn]; //父亲
   int root ,top1,top2; 
   int ss[maxn],que[maxn];
   inline void Rotate(int x ,int f){
       int y = pre[x];
	   push_down(y);
	   push_down(x);
	   ch[y][!f] = ch[x][f]; 
	   pre[ch[x][f]] = y ; 
	   pre[x] = pre[y];
	   if(pre[x])
		   ch[pre[y]][ch[pre[y]][1] == y] = x; 
	   ch[x][f] = y ; 
	   pre[y] = x; 
	   push_up(y);
   }
   void Splay(int x, int goal){
      push_down(x);
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
	  push_up(x);
	  if(goal == 0 ) root = x; 
   }
   void Rotateto(int k ,int goal)
   {
      int x = root; 
	  push_down(x);
	  while(sz[ch[x][0]] != k){
	     if(k < sz[ch[x][0]])
		 {
		     x= ch[x][0];
		 }else {
		     k -=(sz[ch[x][0]]+1);
			 x = ch[x][1];
		 }
		 push_down(x);
	  }
	  Splay(x,goal);
   }
   /*void erase(int x ){
       int father = pre[x];
	   int head = 0 , tail = 0 ; 
	   for()
	   }*/
   void debug(){printf("%d\n",root);Treaval(root);}
   void Treaval(int x) {
	   if(x) {
		   Treaval(ch[x][0]);
		   printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d sum = %3lld\n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x],sum[x]);
		   Treaval(ch[x][1]);
	   }
   }
   void newnode(int &x,int c)
   {
      if(top2) x= ss[--top2];
      else x = ++ top1;
	  ch[x][0] = ch[x][1] = pre[x] = 0 ; 
	  sz[x] = 1;  
	  
	  val[x] = sum[x] = c;
	  add[x] = 0 ; 
   }
   void push_down(int x){
     if(add[x]){
	    val[x] += add[x];
		add[ch[x][0]] += add[x];
		add[ch[x][1]] += add[x];
		sum[ch[x][0]] += (long long)sz[ch[x][0]] * add[x];
		sum[ch[x][1]] += (long long)sz[ch[x][1]] * add[x];
	    add[x] = 0 ;
	 }
   }
   void push_up(int x){
      sz[x] = 1 + sz[ch[x][0]] +sz[ch[x][1]];

	  sum[x] = add[x] + val[x] + sum[ch[x][0]] + sum[ch[x][1]];
   }
   void build(int &x,int l ,int r,int f)
   {
      if(l > r ) return;
	  int m = (l + r) >> 1; 
	  newnode(x,num[m]);
	  build(ch[x][0],l,m-1,x);
	  build(ch[x][1],m+1,r,x); //这里与线段树不同,因为这个节点本身就含有信息
      pre[x] = f;
	  push_up(x);
   }
   void init(int n)
   {
       ch[0][0] = ch[0][1] = pre[0] = sz[0] =0 ; 
	   add[0] = sum[0] =0 ; 
	   root = top1 = 0 ; 
	   newnode(root,-1); //这里注意 root 是从1 开始的
	   //printf("%d\n",top1);
	   
	   newnode(ch[root][1],-1);
	   pre[top1] = root ; 
	   sz[root] = 2;
	   for(int i = 1;i <= n;i ++)
		   scanf("%d",&num[i]);
	   build(keytree,1,n,ch[root][1]);
	   push_up(ch[root][1]);
	   push_up(root);
   }
   void update()
   {
     int l , r, c; 
	 scanf("%d %d %d",&l,&r,&c);
	 Rotateto(l-1,0);
	 Rotateto(r+1,root);
	 add[keytree] += c ; 
	 sum[keytree] += (long long)sz[keytree] * c; 
   }
   void query()
   {
     int l , r; 
	 scanf("%d %d",&l,&r);
	 Rotateto(l-1,0);
	 Rotateto(r+1,root);
	 printf("%lld\n",sum[keytree]);
   }
   int num[maxn];
   int val[maxn];
   int add[maxn];
   long long sum[maxn];
}sp; 
int main(){
   int n , m ; 
   scanf("%d %d",&n,&m);
   sp.init(n);
   while(m--)
   {
      char op[10];
	  scanf("%s",op);
	  if(op[0] == 'Q')
	  {
	    sp.query();
	  }else {
	    sp.update();
	  }
	  //sp.debug();
   }
return 0;
}
