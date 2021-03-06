// File Name: hysbz1500.cpp
// Author: darkdream
// Created Time: 2015年04月10日 星期五 10时41分03秒

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
#include<climits>
#define LL int
#define INF INT_MAX
#define maxn 500005
using namespace std;

struct SplayTree{
   int sz[maxn];
   int ch[maxn][2];
   int pre[maxn];
   int root , top1,top2;
   int ss[maxn],que[maxn];
   
   void Rotate(int x, int f){
		int y = pre[x];
		push_down(y);
		push_down(x);
		ch[y][!f] = ch[x][f];
		pre[ch[x][f]] = y ; 
		pre[x] = pre[y];
		if(pre[x]) ch[pre[y]][ch[pre[y]][1] == y] = x; 
		ch[x][f] = y;
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
				}else{
					Rotate(y,f),Rotate(x,f);
				}
			}
		}
		push_up(x);
		if(goal == 0) root = x; 
   }
   void RotateTo(int k ,int goal){
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
   void erase(int x){
		int father = pre[x];
		int head = 0 , tail = 0 ; 
		for(que[tail ++] = x; head < tail ;head ++){
			ss[top2 ++] = que[head];
			if(ch[ que[head]][0]) que[tail ++] = ch[que[head]][0];
			if(ch[ que[head]][1]) que[tail ++] = ch[que[head]][1];
		}
		ch[father][ch[father][1] ==  x] = 0 ; 
		push_up(father);
   }
   void update_same(int x, int c)
   {
	   if(x == 0 ) return ;
	   cg[x] = c; 
	   val[x] = c; 
	   sum[x] = sz[x] * c; 
	   lx[x] = rx[x] = mx[x] = max(c,c*sz[x]);
   }
   void  update_rev(int x)
   {
	   if(x == 0 )
		   return; 
      rev[x] ^= 1; 
	  swap(lx[x],rx[x]);
   }
   void push_down(int x)
   {
	   if(cg[x] != -INF)
	   {
		   update_same(ch[x][1],cg[x]);
		   update_same(ch[x][0],cg[x]);
		   rev[x] = 0 ; 
		   cg[x] = -INF; 
	   }else if(rev[x] == 1)
	   {
		    swap(ch[x][0],ch[x][1]);
			update_rev(ch[x][0]);
			update_rev(ch[x][1]);
			rev[x] =  0 ; 
	   }
   }
   void push_up(int x){
		sz[x] = 1 + sz[ch[x][0]] + sz[ch[x][1]];
		sum[x] =  val[x] + sum[ch[x][0]] + sum[ch[x][1]] ; 
		lx[x] = rx[x] = sum[x];
		mx[x] = sum[x];
		if(ch[x][0] == 0  && ch[x][1] == 0 ){
		   return; 
		}
		if(ch[x][0] == 0 ){
			lx[x] = max(val[x],lx[x]);
			lx[x] = max(val[x]+lx[ch[x][1]],lx[x]);
			rx[x] = max(rx[ch[x][1]],rx[x]);
			mx[x] = max(mx[ch[x][1]],mx[x]);
			mx[x] = max(lx[x],mx[x]);
			mx[x] = max(rx[x],mx[x]);
		}else if(ch[x][1] == 0 ){
			lx[x] = max(lx[ch[x][0]],lx[x]);
			rx[x] = max(val[x],rx[x]);
			rx[x] = max(val[x] + rx[ch[x][0]],rx[x]);
	    	mx[x] = max(mx[ch[x][0]],mx[x]);
			mx[x] = max(lx[x],mx[x]);
			mx[x] = max(rx[x],mx[x]);
		}else{
			lx[x] = max(lx[ch[x][0]],lx[x]);
			lx[x] = max(sum[ch[x][0]] + val[x],lx[x]);
			lx[x] = max(sum[ch[x][0]] + val[x] + lx[ch[x][1]],lx[x]);		
			rx[x] = max(rx[ch[x][1]],rx[x]);
			rx[x] = max(sum[ch[x][1]] + val[x],rx[x]);
			rx[x] = max(sum[ch[x][1]] + val[x] + rx[ch[x][0]],rx[x]);
			mx[x] = max(val[x],mx[x]);
			mx[x] = max(mx[ch[x][0]],mx[x]);
			mx[x] = max(mx[ch[x][1]],mx[x]);
			mx[x] = max(rx[ch[x][0]]+val[x],mx[x]);
			mx[x] = max(sum[ch[x][0]]+val[x],mx[x]);
			mx[x] = max(lx[ch[x][1]]+val[x],mx[x]);
			mx[x] = max(sum[ch[x][1]]+val[x],mx[x]);
		    mx[x] = max(lx[ch[x][1]]  + rx[ch[x][0]] + val[x],mx[x]);
		}
   }
   void NewNode(int &x , LL c){
		if(top2) x = ss[--top2];
		else x = ++ top1;
		rev[x] = ch[x][0] = ch[x][1] = pre[x] = 0 ;
		sz[x] = 1; 
		cg[x] = -INF;  
		val[x] = sum[x] = lx[x] = rx[x] = mx[x] = c ; 
   }
   void build(int &x,int l ,int r ,int f){
		if(l >  r) return ; 
		int m = (l + r) >> 1; 
		NewNode(x,num[m]);
		build(ch[x][0],l,m-1,x);
		build(ch[x][1],m+1,r,x);
		pre[x] = f; 
		push_up(x);
   }
   void init(){
      rev[0] = ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0 ; 
	  lx[0] = rx[0] = mx[0] = sum[0] = 0;
	  cg[0] = -INF;
	  root = top1 = 0 ; 
	  NewNode(root,-1);
	  NewNode(ch[root][1],-1);
	  pre[ch[root][1]] = root;
	  sz[root] = 2; 
	  push_up(root);
   }
   void insert(int p ,int n){
	   for(int i =1 ;i <= n;i ++)
			scanf("%d",&num[i]);
	   RotateTo(p,0);
	   RotateTo(p+1,root);
	   build(ch[ch[root][1]][0],1,n,ch[root][1]);
	   push_up(ch[root][1]);
	   push_up(root);
   }
   void Del(int p , int n){
		RotateTo(p-1,0);
		RotateTo(p+n,root);
		erase(ch[ch[root][1]][0]);
		push_up(ch[root][1]);
		push_up(root);
   }
   void make(int p , int n, LL c){
		RotateTo(p-1,0);
		RotateTo(p+n,root);
		update_same(ch[ch[root][1]][0],c);
		push_up(ch[root][1]);
		push_up(root);
   }
   void flip(int p ,int n ){
	   RotateTo(p-1,0);
	   RotateTo(p+n,root);
	   update_rev(ch[ch[root][1]][0]);
   }
   LL getsum(int p ,int n){
		RotateTo(p-1,0);
		RotateTo(p+n,root);
		printf("%d\n",sum[ch[ch[root][1]][0]]);
   }
   LL maxsum(){
		RotateTo(0,0);
		RotateTo(sz[root]-1,root);
		LL tmx = -INF;
		tmx = max(lx[ch[ch[root][1]][0]],tmx);
		tmx = max(rx[ch[ch[root][1]][0]],tmx);
		tmx = max(mx[ch[ch[root][1]][0]],tmx);
		printf("%d\n",tmx);
   }
   int rev[maxn];
   LL val[maxn];
   LL sum[maxn];
   LL num[maxn];
   LL mx[maxn];
   LL rx[maxn];
   LL lx[maxn];
   LL cg[maxn];
}spt;
int n , m; 
char str[100];
int ta,tb;
LL tc;
int main(){
  //freopen("in","r",stdin);
  // freopen("output","w",stdout);
	spt.init();
	scanf("%d %d",&n,&m);
	spt.insert(0,n);
	while(m--){
		scanf("%s",str);
		if(str[0] == 'G'){
			scanf("%d %d",&ta,&tb);
			spt.getsum(ta,tb);
		}else if(str[0] == 'I'){
			scanf("%d %d",&ta,&tb);
			spt.insert(ta,tb);
		}else if(str[0] == 'D'){
			scanf("%d %d",&ta,&tb);
			spt.Del(ta,tb);
		}else if(str[0] == 'M' && str[2] == 'K'){
			scanf("%d %d %d",&ta,&tb,&tc);
			spt.make(ta,tb,tc);
		}else if(str[0] == 'R'){
			scanf("%d %d",&ta,&tb);
			spt.flip(ta,tb);
		}else {
		//	spt.debug(spt.root);
			spt.maxsum();
	    /*spt.debug(spt.root);
		printf("\n");
	    spt.print(spt.root);
		printf("\n");
			spt.maxsum();*/
		}
	}
return 0;
}
