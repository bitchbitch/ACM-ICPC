// File Name: hdu1890.cpp
// Author: darkdream
// Created Time: 2014年11月09日 星期日 19时06分59秒

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
#define keytree (ch[ch[root][1]][0])
#define maxn 100010
int num[maxn];
struct node{
 int v, p ; 
}tnum[maxn];
int n; 
struct SplayTree{
    int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int rev[maxn];
	int root ,top1,top2;
	void push_up(int k )
	{
	    sz[k] =1 + sz[ch[k][0]] + sz[ch[k][1]];
	}
	void push_down(int k )
	{
	     if(rev[k])
		 {
		    //printf("(((\n");
	        swap(ch[k][1],ch[k][0]);	
			rev[ch[k][1]] ^= 1;
			rev[ch[k][0]] ^= 1; 
			rev[k] = 0 ;  
		 }
	}
	void Rotate(int x, int f){
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
			}else {
			   int y = pre[x],z = pre[y];
			   int f = (ch[z][0] == y);
			   if(ch[y][f] == x){
			      Rotate(x,!f),Rotate(x,f);
			   }else {
			      Rotate(y,f),Rotate(x,f);
			   }
			}
		}
		push_up(x);
		if(goal == 0 )
			root = x; 
	}
	void Delete()
	{
	   push_down(root);
       ch[ch[root][0]][1] = ch[root][1];
	   pre[ch[root][1]] = ch[root][0];
	   root = ch[root][0];
	   pre[root] = 0 ; 
	   push_up(root);
	}
	void Rotateto(int k ,int pp){
	  push_down(k+1);
	  Splay(k+1,0);
	  printf("%d",sz[ch[root][0]]+pp-1);
      if(pp != n)
		  printf(" ");
	  Splay(1,root);
	  rev[ch[ch[root][0]][1]] ^= 1; 
	  int x = ch[root][0];
      push_down(x);
	  while(ch[x][1])
	  {
	    x = ch[x][1];
	    push_down(x);
	  }
      Splay(x,root);
	  Delete();
	}
	void newnode(int &x,int c)
	{
	   x = c ;
	   ch[x][0] = ch[x][1] = pre[x]= 0; 
	   rev[x] = 0;
	   sz[x] = 1; 
	}
	void build(int &x,int l ,int r ,int f){
	   if(l > r )return;
	   int m = (l + r) >> 1; 
	   newnode(x,m);
	   build(ch[x][0],l,m-1,x);
	   build(ch[x][1],m+1,r,x);
	   pre[x] = f; 
	   push_up(x);
	}
    void init(int n){
	   sz[0] = rev[0] = ch[0][0] = ch[0][1] = pre[0] = 0 ; 
	   num[1] = -1; 
	   num[n+2] = -1;
	   for(int i = 2 ;i <= n+1;i ++ )
	   {
		   scanf("%d",&num[i]);
		   tnum[i-1].v = num[i];
		   tnum[i-1].p = i-1;
	   }
	   build(root,1,n+2,0);
       push_up(root);
	} 
}sp;
int cmp(node a, node  b )
{
	return a.v < b.v;
}
int main(){  
   while(scanf("%d",&n) != EOF)
   {
     if(n == 0 )
		 break;
	 sp.init(n);
     sort(tnum+1,tnum+1+n,cmp);
     for(int i = 1;i <= n;i ++)
	 {
	//	printf("sz = %d\n\n",sp.sz[sp.root]);
	    sp.Rotateto(tnum[i].p,i);    
	 }
	 printf("\n");
   }
return 0;
}
