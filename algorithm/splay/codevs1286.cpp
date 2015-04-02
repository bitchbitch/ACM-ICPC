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
#define maxn 100010
using namespace std;
#define keytree ch[ch[root][1]][0]
int lim;
int Lsum = 0 ;
struct SplayTree{
	int sz[maxn];   //大小
	int ch[maxn][2];  //儿子
	int pre[maxn]; //父亲
	int root,top1,top2; 
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
	void Delete(int x ){
		if(x == 0 )
			return ;
		Lsum += sz[x];
		int father = pre[x];
		int head = 0 , tail = 0 ; 
		for(que[tail ++] = x ; head < tail; head ++)
		{
			ss[top2++] = que[head];
			if(ch[que[head]][0])  que[tail ++] = ch[que[head]][0];
			if(ch[que[head]][1])  que[tail ++] = ch[que[head]][1];
		}
		ch[father][ch[father][1] == x] = 0 ; 
		push_up(father);
	}
	void debug(){printf("%d\n",root);Treaval(root);}
	void Treaval(int x) {
		if(x) {
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2lld \n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x]);
			Treaval(ch[x][1]);
		}
	}
	void newnode(int &x, LL c)
	{
		if(top2) x= ss[--top2];
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0 ; 
		sz[x] = 1;  
		val[x] = c ;  
		add[x] = 0 ; 
	}
	void push_down(int x){
		if(add[x]){
			val[x] += add[x];
			add[ch[x][0]] += add[x];
			add[ch[x][1]] += add[x];
			add[x] = 0 ;
		}
	}
	void push_up(int x){
		sz[x] = 1 + sz[ch[x][0]] +sz[ch[x][1]];
	}


	void clear(){
		int x = root;      
		push_down(x);
		int t = x;
		int mi = INT_MAX;
		while(ch[x][val[x] < lim])
		{
			//	 printf("***%lld\n",val[x]);
			if(val[x] >= lim && val[x] - lim < mi)
			{
				t = x; 
				mi = val[x] - lim;
			}
			x = ch[x][val[x] <= lim];
			push_down(x);
		}
		if(val[x] >= lim && val[x] - lim < mi)
		{
			t = x; 
			mi = val[x] - lim;
		}
		x = t; 
		// printf("********%lld\n",val[x]);
		Splay(x,0);
		Splay(1,root);
		Delete(ch[ch[root][0]][1]);
	}
	void init(){ 
		ch[0][1] = ch[0][0] = pre[0] = 0 ; 
		sz[0] = 0 ; 
		add[0] = 0 ; 
		newnode(root,-1e17);
		newnode(ch[root][1],1e17);
		pre[ch[root][1]] = root;
		sz[root] = 2; 
	}
	void find(int k ){
		clear();
		//printf("****%d****\n",sz[root]);
		if(k >sz[root]-2)
		{
			puts("-1");
			return;
		}
		int x = root; 
		push_down(x);;
		while(sz[ch[x][1]] != k)
		{
			if(k < sz[ch[x][1]])
				x = ch[x][1];
			else{
				k -= (sz[ch[x][1]] + 1);
				x =ch[x][0]; 
			}
			push_down(x);
		}
		printf("%lld\n",val[x]);
		Splay(x,0);
		// print(root);
		//  printf("\n");
	}
	void insert(int v)
	{
		if(v < lim)
			return;
		int x = root ;
		push_down(x);
		while(ch[x][val[x] <= v])
		{
			x = ch[x][val[x] <= v ];
			push_down(x);
		}
		newnode(ch[x][val[x] <= v],v);
		pre[ch[x][val[x] <= v]] = x; 
		Splay(ch[x][val[x] <=  v],0);
		//print(root);
		//printf("\n");
		clear();
	}
	void print(int x)
	{
		if(x == 0 )
			return;
		push_down(x);
		print(ch[x][0]);
		printf("%lld ",val[x]);
		print(ch[x][1]);

	}
	void update(LL v)
	{
		add[root] += v;
		clear();

		//print(root);
		//printf("\n");
	}
	LL val[maxn];
	LL add[maxn];
}sp; 
int main(){
	int q, k; 
	scanf("%d %d",&q,&lim);
	char op[10];
	sp.init();
	while(q--)
	{
		scanf("%s %d",op,&k);
		if(op[0] == 'I'){
			sp.insert(k);
		}else if(op[0] == 'A'){
			sp.update(k);
		}else if(op[0] == 'S'){
			sp.update(-k);
		}else{
			sp.find(k);
		}
	}
	printf("%d\n",Lsum);
	return 0;
}

