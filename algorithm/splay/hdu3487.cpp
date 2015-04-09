// File Name: hdu3487.cpp
// Author: darkdream
// Created Time: 2015年04月09日 星期四 10时16分12秒

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
#define maxn 310000
using namespace std;

char str[10];
int ta,tb,tc;
int n , m ; 
int lastans[maxn];
struct SplayTree{
	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int root ,top1,top2;
	int ss[maxn],que[maxn];
	int rev[maxn];
    inline void Rotate(int x, int f){
		int y = pre[x];
		push_down(y);
		push_down(x);
		ch[y][!f] = ch[x][f];
		pre[ch[x][f]] = y ; 
		pre[x] = pre[y];
		if(pre[x]) ch[pre[y]][ch[pre[y]][1] == y]  = x; 
		ch[x][f] = y; 
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
				int f = (ch[z][0] == y);
				if(ch[y][f] == y ){
					Rotate(x,!f),Rotate(x,f);
				}else{
					Rotate(y,f),Rotate(x,f);
				}
			}
		}
		push_up(x);
		if(goal == 0 ) root = x;
	}
	inline void RotateTo(int k ,int goal){
		int x = root ; 
		push_down(x);
		while(sz[ch[x][0]] != k ){
			if(k < sz[ch[x][0]]){
				x = ch[x][0];
			}else{
			    k -= (sz[ch[x][0]] +1) ; 
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x,goal);
	}
	inline void NewNode(int &x ,int c){
		 if(top2) x = ss[--top2];
		 else x = ++ top1;
		 ch[x][0] = ch[x][1] = pre[x] = 0 ; 
		 sz[x] = 1; 
		 
		 val[x] = c ;
		 rev[x] = 0 ;

	}
	inline void push_down(int x){
		if(rev[x])
		{
			swap(ch[x][0],ch[x][1]);
			rev[ch[x][0]] ^= 1; 
			rev[ch[x][1]] ^= 1; 
			rev[x] = 0 ; 
		}
	}
	inline void push_up(int x){
	    sz[x] = 1 + sz[ch[x][0]] + sz[ch[x][1]];
	}
	inline void makeTree(int &x, int l ,int r ,int f){
		if(l > r) return ;
		int m = (l + r) >> 1; 
		NewNode(x, m);
		makeTree(ch[x][0] , l , m-1, x);
	    makeTree(ch[x][1] , m+1 , r, x);
		pre[x] = f; 
		push_up(x);
	}
	inline void init(int n){
		rev[0] = ch[0][1] = ch[0][0] = pre[0] = sz[0] = 0 ;
		root  = top1 =0 ; 
		NewNode(root,-1);
		NewNode(ch[root][1],-1);
		pre[ch[root][1]] = root ;
		sz[root] = 2; 
	
		makeTree(ch[ch[root][1]][0],1,n,ch[root][1]);
		push_up(ch[root][1]);
		push_up(root);
	}
	inline void cut(int l,int r, int si){
	
        RotateTo(l-1,0);
		RotateTo(r+1,root);

		int del = ch[ch[root][1]][0];
		ch[ch[root][1]][0] = 0 ; 
		push_up(ch[root][1]);
		push_up(root);
		RotateTo(si,0);
		RotateTo(si+1,root);
		pre[del] = ch[root][1];
		ch[ch[root][1]][0] = del ;
		Splay(ch[ch[root][1]][0],0);
		//push_up(ch[root][1]);
		//push_up(root);
	}
	inline void flip(int l , int r )
	{
        RotateTo(l-1,0);
		RotateTo(r+1,root);
		rev[ch[ch[root][1]][0]] ^= 1; 
		Splay(ch[ch[root][1]][0],0);
	}
	void print(int x,int k ){
		if(x == 0 )
			return;
		push_down(x);
		print(ch[x][0],k);
		lastans[k+sz[ch[x][0]]] = val[x]; 
	    print(ch[x][1],k+1+sz[ch[x][0]]);
	}
	int val[maxn];

}spt;
int main(){ 
	while(scanf("%d %d",&n,&m) != EOF)
	{
	   if(n == -1)
		   break;
	   spt.init(n);
	   for(int i = 1;i <= m;i ++)
	   {
		   scanf("%s",str);
		   if(str[0] == 'C')
		   {
		      scanf("%d %d %d",&ta,&tb,&tc);
			  spt.cut(ta,tb,tc);
		   }else{
		      scanf("%d %d",&ta,&tb);
			  spt.flip(ta,tb);
		   }
	   }
	   spt.print(spt.root,0);
	   for(int i = 1;i <= n; i ++)
	     printf(i == 1?"%d":" %d",lastans[i]);
	   printf("\n");
	}
return 0;
}
