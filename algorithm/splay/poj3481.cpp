// File Name: poj3481.cpp
// Author: darkdream
// Created Time: 2015年04月09日 星期四 14时41分43秒

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
#define maxn 100005
using namespace std;

struct SplayTree{
	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int root , top1,top2;
	int ss[maxn],que[maxn];
	inline void Rotate(int x, int f){
		int y = pre[x];
		push_down(y);
		push_down(x);
		ch[y][!f] = ch[x][f];
		pre[ ch[x][f] ] = y  ; 
		pre[x] = pre[y];
		if( pre[x] ) ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;  
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
		int x = root ;
		push_down(x);
		while(sz[ch[x][0]] != k){
			if(k < sz[ch[x][0]]){
				x = ch[x][0];
			}else{
				k -= (sz[ch[x][0]] + 1);
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x,goal);
	}
	inline void erase(int x)
	{
	   int father = pre[x];
	   int head = 0 , tail =0 ; 
	   for(que[tail++] = x ; head < tail ; head ++){
          ss[top2++] = que[head];
		  if(ch[que[head]][0] )  que[tail ++] = ch[que[head]][0];
		  if(ch[que[head]][1] )  que[tail ++] = ch[que[head]][1];
	   }
	   ch[father][ch[father][1] == x] =0 ; 
	   push_up(father);
	}
	inline void NewNode(int &x, int key ,int val){
		if(top2) x = ss[--top2];
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0 ; 
		sz[x] = 1; 
		
		vals[x] = val;
		keys[x] = key ;
	}
	
	void init(){
		ch[0][0] = ch[0][1] = sz[0] = pre[0] = 0 ;
		root = top1 =0 ; 
		NewNode(root,0,0);
		NewNode(ch[root][1],1e9,0);
		sz[root] = 2;
		pre[ch[root][1]] = root; 
	}
	void push_up(int x){
		sz[x] = 1 + sz[ch[x][0]] + sz[ch[x][1]];
	}
	void push_down(int x){
	
	}
	void insert(int key,int val){
         int x = root ;
		 for(;;){
		     int f = (key > keys[x]);
			 if(ch[x][f] == 0 ){
				 NewNode(ch[x][f],key,val);
				 pre[ch[x][f]] = x; 
				 Splay(ch[x][f],0);
				 return ; 
			 }else{
				x = ch[x][f];
			 }
		 }
	}
	void Del(int rank){
		//printf("%d***\n",rank);
		RotateTo(rank-1,0);
		RotateTo(rank+1,root);
	//	printf("%d %d\n",keys[root],keys[ch[root][1]]);
		printf("%d\n",vals[ch[ch[root][1]][0]]);
		erase(ch[ch[root][1]][0]);
		push_up(root);
	//	printf("****");
	}
	int keys[maxn];
	int vals[maxn];
}spt;
int n ;
int key,val;
int main(){
	  spt.init();
      while(scanf("%d",&n) != EOF && n )
	  {
		 int sz = spt.sz[spt.root];
	     if(n == 2 )
		 {
		    if(sz> 2){
				spt.Del(sz-2);
			}else{
			  printf("0\n");
			}
		 }else if(n == 3){
		    if(sz> 2){
				spt.Del(1);
			}else{
			  printf("0\n");
			}
		 }else{
			scanf("%d %d",&val,&key);
			spt.insert(key,val);
		 }
	//	 sz = spt.sz[spt.root];
	//	 printf("%d\n",sz);
	  }
return 0;
}
