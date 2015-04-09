// File Name: hdu3436.pb_ds.cpp
// Author: darkdream
// Created Time: 2015年04月07日 星期二 14时26分13秒

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
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define maxn 100005

#define LL long long

using namespace __gnu_pbds;
using namespace std;
tree<int,int,greater<int>,rb_tree_tag,tree_order_statistics_node_update> mp; 
int T; 
int n , q;
char str[10];
int tmp ; 
struct SplayTree{
	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int root ,top1,top2;
	int ss[maxn],que[maxn];
	inline void Rotate(int x ,int f){
	      int y = pre[x];
		  push_down(y);
		  push_down(x);
		  ch[y][!f] = ch[x][f];
		  pre[ ch[x][f] ] = y ;
		  pre[x] = pre[y];
		  if(pre[x])  ch[pre[y]][ch[pre[y]][1] == y] = x; 
		  ch[x][f] = y ; 
		  pre[y] = x; 
		  push_up(y);
	}
	inline void Splay(int x ,int goal){
		push_down(x);
		while(pre[x] != goal){
			if(pre[ pre[x] ] == goal){
				Rotate(x,ch[pre[x]][0] == x);	
			} else {
				int y = pre[x],z = pre[y];
				int f = (ch[z][0] == y);
				if(ch[y][f] == x){
					Rotate(x,!f),Rotate(x,f);
				} else{
					Rotate(y,f), Rotate(x,f);
				}
			}
		}
		push_up(x);
		if(goal == 0 ) root = x; 
	}
	inline void RotateTo(int k ,int goal){
		int x = root;
		push_down(x);
		while(sz[ch[x][0]] != k ){
			if(k < sz[ch[x][0]]){
				x = ch[x][0];
			}else{
				k -=(sz[ch[x][0]] + 1);
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x,goal);
	}
	inline void NewNode(int &x ,int key,int val){
		if(top2) x = ss[--top2];
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0 ; 
		sz[x] = 1; 
		keys[x]= key; 
		vals[x] = val ; 
	}
	inline void push_down(int x){
	
	}
	inline void push_up(int x){
	   sz[x] = 1 + sz[ch[x][1]] + sz[ch[x][0]];
	}
	inline void init(){
		ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0 ; 
		root = top1 = 0 ; 
		NewNode(root,0,0);
		NewNode(ch[root][1],1e9,0);
		sz[root] = 2; 
		pre[ch[root][1]] = root;

	}
	inline pair<int,int> find(int key)
	{
        int x = root ;  
		int k = 0 ; 
		for(;;)
		{
	       if(key == keys[x])
		   {
			   pair<int,int> ans =  make_pair(vals[x],k+sz[ch[x][0]]);
			   Splay(x,0);
			   return ans; 
		   }
		   bool f = (key > keys[x]);
		   if(ch[x][f] == 0 )
		   {
		     pair<int,int> ans = make_pair(-1,k + sz[ch[x][0]] - (!f));   
			 Splay(x,0);
			 return ans ;

		   }else{
			 if(f)
				k += (sz[ch[x][0]] + 1); 
		     x = ch[x][f];
		   }
		}
	}
	inline void insert(int key,int val){
		int x = root; 	
		int k = 0 ; 
		for(;;)
		{
			if(key == keys[x])
		    {
				mp.erase(mp.find(vals[x]));
			    vals[x] = val;  	
				Splay(x,0);
			    return; 
			}
			int f = (key > keys[x]);
			if(ch[x][f] == 0 )
			{
			    NewNode(ch[x][f],key,val);
				pre[ch[x][f]] = x; 
				Splay(ch[x][f],0);
			    return;
			}else{
			   x = ch[x][f];
			}
		}
	}
	inline int  findrank(int site){	
		int x = root ;
		int k = 0 ; 
		int szmp= mp.size();
		int ans = site;  
		int p  = root;
		for(; x!= 0 ;)
		{
	       int tmp = szmp + keys[x] - (k + sz[ch[x][0]]) + 1;	
		   //printf("***%d %d %d %d\n",keys[x],k,sz[ch[x][0]],sz[ch[x][1]]);
		   if(tmp > site)
		   {
		       x = ch[x][0];
		   }else{
			  ans = keys[x] + (site - (tmp) + 1) ;  
			  p = x; 
			  //printf("%d %d\n",tmp,keys[x]);
			  k += (sz[ch[x][0]] + 1);
			  x = ch[x][1];
		   }
		}
		Splay(p,0);
		return ans;   
	}
	int vals[maxn];
	int keys[maxn];

}spt;
int main(){
   scanf("%d",&T);
   for(int CA = 1; CA <= T ; CA++)
   {
	  mp.clear();
	  spt.init();
	  //printf("%d\n",spt.sz[spt.root]);
	  printf("Case %d:\n",CA);

	  scanf("%d %d",&n,&q);
	  for(int i= 1;i <= q;i ++)
	  {
		scanf("%s %d",str,&tmp);
		if(str[0] == 'T'){
			spt.insert(tmp,i);
			mp[i] = tmp ; 
	     }else if(str[0] == 'Q'){
			pair<int ,int > tt = spt.find(tmp);
			if(tt.first != -1 )
              printf("%ld\n",mp.order_of_key(tt.first) + 1);
			else{
		      printf("%ld\n",mp.size()-tt.second + tmp); 	
			}
		}else{
			if(tmp <= mp.size()){
				printf("%d\n",mp.find_by_order(tmp-1)->second);
			}else{
                printf("%d\n",spt.findrank(tmp)); 
			}
		}
	  }
   }
return 0;
}
