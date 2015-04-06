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
#include<limits.h>
#define LL long long
#define keyTree (ch[ch[root][1]][0])
using namespace std;
const int maxn = 100005; 
int flag = 0 ; 

struct SplayTree{
    int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int root ,top1,top2;
	int ss[maxn],que[maxn];
	struct node{
	  int i,si,val;
	}num[maxn];
	static bool cmp(node a,node b)
	{
	  return a.i < b.i; 
	}
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
	inline void RotateTo(int k ,int goal){
		int x = root;
		push_down(x);
		while(sz[ch[x][0]] != k)
		{
			if(k < sz[ch[x][0]]){
				x = ch[x][0];
			}else{
				k-= (sz[ch[x][0]] +1);
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x,goal);
	}
	void print(int x){
		if(x == 0 )
			return ;
		print(ch[x][0]);
		printf("%d ",val[x]);
		print(ch[x][1]);
	}
	inline int findK(int mxnum){
		int k = 0 ; 
        for(int i = root;i != 0 ;)
		{
			push_down(i);
	        if(val[i] == mi[root])
			{
			   k += sz[ch[i][0]] ;
			   RotateTo(0,0);
               RotateTo(k+1,root);
			   rev[keyTree] ^= 1;
			   RotateTo(0,0);
			   RotateTo(2,root);
			   erase(keyTree);
		       push_up(ch[root][1]);
		       push_up(root);
			   return k ; 
			}
			if(mi[ch[i][1]] == mi[root])
			{
				k += sz[ch[i][0]] + 1; 
				i = ch[i][1];
			}
			else{ 
				i = ch[i][0];
			    /*printf("****%d\n",k);
				for(int i = 1;i <= 6; i++)
					printf("%d ",sz[i]);
				printf("\n");*/
			}
		}
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
		NewNode(x,num[m].val);
	//	printf("%d %d\n",x,num[m]);
		makeTree(ch[x][0],l,m-1,x);
		makeTree(ch[x][1],m+1,r,x);
		pre[x] = f; 
		push_up(x);
	}
	static bool cmp2(SplayTree::node a, SplayTree::node b)
	{
	  return a.si < b.si;
	}
	inline void init(int n){
		ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0 ; 
		rev[0] = 0; 
		mi[0] = INT_MAX;
	
		root = top1 = top2 = 0 ; 

		NewNode(root,INT_MAX);
		NewNode(ch[root][1],INT_MAX);
		pre[top1] = root;
		sz[root] = 2; 
		
		for(int i = 1 ;i <= n;i ++) 
		{
			scanf("%d",&num[i].i);
			num[i].si = i ; 
		}
		stable_sort(num+1,num+n+1,cmp);
        for(int i = 1;i <= n;i ++)
		{
		    num[i].val = i; 
		}
		sort(num+1,num+n+1,SplayTree::cmp2);
		makeTree(keyTree,1,n,ch[root][1]);
		push_up(ch[root][1]);
		push_up(root);
	}
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
			printf(i == 1?"%d":" %d",i-1+spt.findK(n-i+2));
		}
		printf("\n");
	}
return 0;
}
