// File Name: hdu1890.1.cpp
// Author: darkdream
// Created Time: 2015年04月04日 星期六 21时28分31秒

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
#define keyTree (ch[ch[root][1]][0])
using namespace std;
const int maxn = 100005; 

struct SplayTree{
    int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int root ,top1,top2;
	int ss[maxn],que[maxn];
	
	inline void Rotate(int x, int f){
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
		while(pre[x] != goal){
			if(pre[pre[x]] == goal){
			   Rotate(x,ch[pre[x]][0] == x);
			}else{
				int y = pre[x],z = pre[y];
				int f = (ch[z][0] == y );
				if(ch[y][f] == x)
					Rotate(x,!f),Rotate(x,f);
				else Rotate(y,f),Rotate(x,f);
			}
		}
		push_up(x);
		if(goal == 0 ) root = x; 
	}
	inline int RotateTo(){

	}
    inline void erase(int x){
	    int father = pre[x];
		int head = 0 ,tail =0 ; 
		for(que[tail++] = x ;head < tail ;head ++){
		   ss[top2 ++ ] = que[head];
		   if(ch[que[head]][0])  que[tail ++] = ch[que[head]][0];
		   if(ch[que[head]][1])  que[tail ++] = ch[que[head]][1];
		}
		ch[father][ch[father][1] == x] = 0 ; 
		push_up(father);
	}

	inline void NewNode(int &x,int c){
		if(top2) x = ss[--top2];
		else x = ++ top1;
		ch[x][0] = ch[x][1] = pre[x] = rev[x] = 0 ; 
		sz[x] = 1; 
		val[x] = mi[x] = c; 
	}
	inline void push_down(int x)
	{
       if(rev[x]){
	       swap(ch[x][0],ch[x][1]);
		   rev[ch[x][0]] ^= 1;
		   rev[ch[x][1]] ^= 1;
           rev[x] = 0;
	   }	
	}
	inline void push_up(int x)
	{
         sz[x] = 1 + sz[ch[x][0]] + sz[ch[x][1]];
	     mi[x] = min(val[x],mi[ch[x][0]]) ;	
	     mi[x] = min(mi[x],mi[ch[x][1]]) ;	
	}
	inline void makeTree(int &x ,int l ,int r ,int f){
		if(l > r ) return;
		int m = (l + r) >> 1; 
		NewNode(x,num[m]);
		makeTree(ch[x][0],l,m-1,x);
		makeTree(ch[x][1],m+1,r,x);
		pre[x] = f; 
		push_up(x);
	}
	inline void init(int n){
		ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0 ; 
		rev[0] = 0; 
	
		root = top1 = 0 ; 
		NewNode(root,-1);
		NewNode(ch[root][1],-1);
		pre[top1] = root;
		sz[root] = 2; 
		
		for(int i = 1 ;i <= n;i ++) scanf("%d",&num[i]);
		makeTree(keyTree,1,n,ch[root][1]);
		push_up(ch[root][1]);
		push_up(root);
	}
	int num[maxn];
	int mi[maxn];
	int rev[maxn];
	int val[maxn];
}spt;
int n ; 
int main(){
	while(scanf("%d",&n) != EOF && n)
	{
	  spt.init(n);
	  for(int i = 1;i <= n;i ++)
	  {
	    printf("%d\n",i-1+spt.RotateTo());
	  }
	}
return 0;
}
