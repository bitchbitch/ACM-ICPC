// File Name: hdu1754.cpp
// Author: darkdream
// Created Time: 2015年04月03日 星期五 22时06分59秒

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
const int maxn = 200005;
struct SplayTree{
    int sz[maxn];
    int ch[maxn][2];
    int pre[maxn];
    int root ,top1,top2;
    int ss[maxn],que[maxn];
    
    inline void Rotate(int x,int f){
        int y = pre[x];
        push_down(y);
        push_down(x);
        ch[y][!f] = ch[x][f];
        pre[ch[x][f]] = y ; 
        pre[x] = pre[y];
        if(pre[x]) ch[pre[y]][ch[pre[y]][1] == y] = x; 
        ch[x][f] = y ; 
        pre[y] = x ; 
        push_up(y);
    }
    inline void Splay(int x, int goal){
         push_down(x);
         while(pre[x] != goal){
            if(pre[pre[x]] == goal){
                Rotate(x, ch[pre[x]][0] == x);
            }else{
               int y = pre[x],z = pre[y];
               int f = (ch[z][0] == y);
               if(ch[y][f] == x){
                    Rotate(x,!f) , Rotate(x,f);
               }else{
                    Rotate(y,f) , Rotate(x,f);
               }
            }
         }
         push_up(x);
         if(goal ==  0) root = x; 
    }
    inline void RotateTo(int k ,int goal){
        int x = root;
        push_down(x);
        while(sz[ch[x][0]] != k ){
            if(k < sz[ ch[x][0] ]){
                x = ch[x][0];
            }else{
                k -= (sz[ch[x][0]] + 1);
                x = ch[x][1];
            }
            push_down(x);
        }
        Splay(x,goal);
    }
    inline void erase(int x){
        int father = pre[x];
        int head = 0 , tail = 0 ; 
        for(que[tail ++] = x ; head < tail ;head ++){
            ss[top2++] = que[head];
            if(ch[que[head] ][0]) que[tail ++] = ch[que[head]][0];
            if(ch[que[head] ][1]) que[tail ++] = ch[que[head]][1];
        }
        ch[father][ch[father][1] == x] = 0 ;
        push_up(father);
    }
    inline void NewNode(int &x,int c){
         if(top2) x = ss[--top2];
         else x = ++top1;
         ch[x][0] = ch[x][1] = pre[x] = 0 ; 
         sz[x] = 1; 
         val[x] = mx[x] = c;
    }
    inline void push_down(int x){

    }
    inline void push_up(int x){
        sz[x] = 1 + sz[ch[x][0]] + sz[ch[x][1]]; 
        mx[x] = max(mx[ch[x][0]],val[x]);
		mx[x] = max(mx[ch[x][1]],mx[x]);    
    }
    inline void makeTree(int &x,int l ,int r,int f){
        if(l > r) return ; 
        int m = (l + r ) >> 1; 
        NewNode(x,num[m]);
        makeTree(ch[x][0],l,m-1,x);
        makeTree(ch[x][1],m+1,r,x);
        pre[x] = f;
        push_up(x);
    }
    inline void init(int n){
        ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0 ; 
        mx[0] = 0 ; 
        root = top1 = 0 ; 
        NewNode(root,-1);
        NewNode(ch[root][1],-1);
        pre[top1] = root;
        sz[root] = 2; 
	//	printf("%d***\n",mx[root]);

        for(int i =  1 ;i <= n;i ++) scanf("%d",&num[i]);
        makeTree(ch[ch[root][1]][0],1,n,ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);
		
	//	printf("%d***\n",mx[root]);

    }
    inline void update(int l,int v){
      RotateTo(l,0);
      val[root] = v;
	//  push_up(root);
    }
    inline void query(int l , int r){
       RotateTo(l-1,0);
       RotateTo(r+1,root);
       printf("%d\n",mx[ch[ch[root][1]][0]]);
    } 
    int num[maxn];
    int mx[maxn];
    int val[maxn];
}spt;
char str[10];
int ta,tb;
int n , q; 
int main(){
    while(scanf("%d %d",&n,&q) != EOF)
	{
	    spt.init(n);
		for(int i = 1;i <= q; i++)
		{
		  scanf("%s %d %d",str,&ta,&tb);
		  if(str[0] == 'Q')
		  {
		    spt.query(ta,tb);
		  }else{
		    spt.update(ta,tb);
		  }
		}
	}
return 0;
}
