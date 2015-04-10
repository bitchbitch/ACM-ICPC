// File Name: hysbz1269.cpp
// Author: darkdream
// Created Time: 2015年04月09日 星期四 19时53分30秒

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
#define maxn 2*1024*1024+10
using namespace std;
int sp;
struct SplayTree{
	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int top1,top2,root ;
	int que[maxn];
	int ss[maxn];
	inline void Rotate(int x,int f){
		int y = pre[x];
		push_down(y);
		push_down(x);
		ch[y][!f] = ch[x][f];
		pre[ch[x][f]] = y; 
		pre[x] = pre[y];
		if(pre[x]) ch[pre[y]][ch[pre[y]][1] == y ] = x; 
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
				int f = (ch[z][0] == y);
			    if(ch[y][f] == x){
					Rotate(x,!f),Rotate(x,f);
				}else{
					Rotate(y,f),Rotate(x,f);
				}
			}
		}
		push_up(x);
		if(goal == 0) root = x; 
	}
	inline void RotateTo(int k ,int goal){
		int x = root;  
		push_down(x);
		while(sz[ch[x][0]] != k ){
			if(k < sz[ch[x][0]]){
				x = ch[x][0];
			}else {
				k -= (sz[ch[x][0]] + 1);
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x,goal);
	}
	inline void erase(int x){
		if(x == 0 )
			return ;
		int father = pre[x];
		int head = 0 , tail = 0 ; 
		for(que[tail ++ ] = x ; head < tail ; head ++){
			ss[top2 ++ ] = que[head];
			if(ch[ que[head]][0]) que[tail++] = ch[que[head]][0];
			if(ch[ que[head]][1]) que[tail++] = ch[que[head]][1];
		}
		ch[father][ch[father][1] == x] = 0 ;
		push_up(father);
	}
	
	inline void NewNode(int &x ,char c){
		if(top2) x = ss[--top2];
		else x = ++ top1;
		ch[x][0] = ch[x][1] = pre[x] = 0 ; 
		rev[x] = 0 ;
		sz[x] = 1; 
		val[x] = c; 
	}

	inline void push_down(int x){
		if(rev[x])
		{
		     swap(ch[x][1],ch[x][0]);
			 rev[ch[x][1]] ^= 1; 
			 rev[ch[x][0]] ^= 1; 
			 rev[x] = 0 ; 
		}
	}

	inline void push_up(int x){
		sz[x] = 1 + sz[ch[x][0]] + sz[ch[x][1]];
	}

	inline void build(int &x, int l , int r , int f){
		if(l > r) return ; 
		int m = (l + r) >> 1; 
		NewNode(x, str[m]);
		build(ch[x][0] ,l,m-1,x);
		build(ch[x][1] ,m+1,r,x);
		pre[x] = f; 
		push_up(x);
	}
	
	inline void init(){
		 rev[0] = ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0 ; 

		root = top1 = 0 ; 
		NewNode(root,' ');
		NewNode(ch[root][1],'\n');
		pre[top1] = root ;
		sz[root] = 2; 
	}

	inline void insert(int n ){
	  if(n == 0 )
		  return ;
       RotateTo(sp,0);
	   RotateTo(sp+1,root);
	   scanf("%[^\n]",str);
	   if(n == 0 )
		   return ;
	   build(ch[ch[root][1]][0],0,n-1,ch[root][1]);
	   push_up(ch[root][1]);
	   push_up(root);
	   //可能需要splay 优化
	}

	inline void Del(int n){
		if(n == 0 )
			return ;
	   //printf("***\n");
	  // printf("%d %d\n",sp,min(sp+n+1,sz[root]-2))
	   RotateTo(sp,0);	
	   RotateTo(min(sp+n+1,sz[root]-1),root);
	   //printf("***\n");
	   erase(ch[ch[root][1]][0]);
	   //printf("***\n");
	   push_up(ch[root][1]);
	   push_up(root);
	}  
	inline void flip(int n){	
		if(n == 0 )
			return ; 
		RotateTo(sp,0);
		RotateTo(min(sp+n+1,sz[root]-1),root);
		rev[ch[ch[root][1]][0]] ^= 1; 
	}

	inline void get(){
		RotateTo(sp+1,0);
		printf("%c\n",val[root]);
	}

	void print(int x){
	   //printf("%d\n",x);
	   if(x == 0 )
		   return ;
	   print(ch[x][0]);
	   printf("%c",val[x]);
	   print(ch[x][1]);
	}

	char val[maxn];
	char str[maxn];
	char rev[maxn];
}spt;
int n; 
char str[100];
int tmp ;
int main(){
	scanf("%d",&n);
	spt.init();
	sp = 0 ; 
	while(n--)
	{
		scanf("%s",str);
		if(str[0] == 'I'){	
			scanf("%d",&tmp);
			getchar();
			spt.insert(tmp);
		}else if(str[0] == 'M'){
			scanf("%d",&tmp);
			sp = min(spt.sz[spt.root] - 2,tmp);
		}else if(str[0] == 'D'){
		    scanf("%d",&tmp);
			spt.Del(tmp);
		}else if(str[0] == 'R'){
			scanf("%d",&tmp);
			spt.flip(tmp);
		}else if(str[0] == 'P'){
		    sp = max(0,sp-1);
		}else if(str[0] == 'N'){
		    sp = min(spt.sz[spt.root] - 2, sp + 1);
		}else { 
		    spt.get();
		}
		//spt.print(spt.root);
		//printf("%d\n",spt.sz[spt.root]);
	}

return 0;
}
