// File Name: 1852.cpp
// Author: darkdream
// Created Time: 2014年07月23日 星期三 09时03分05秒

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

using namespace std;
const int inf = ~0U>>1;
int ans;
int s; 
class treap{
    struct node{
	    int value,key,size;
		node(int v, node *n):value(v)
		{
		  c[0] = c[1] = n ; 
		  size = 1; 
		  key = rand() - 1; 
		}
		node *c[2];
	}*root,*null;
	void rot(node *&t,bool d)
	{
	    node *c = t->c[d];
		t->c[d] = c->c[!d];
		c->c[!d] = t; 
		t = c ;
	}
	void insert(node *&t, int x)
	{
	   if(t == null) { 
	     t = new node(x,null);
		 return ; 
	   }
	   if(x == t->value)
		   return ; 
	   bool d = x > t->value;
	   insert(t->c[d],x);
	   if(t->c[d]->key < t->key)
	      rot(t,d);
	}
	void Delete(node *&t ,int x)
	{
	   if(t == null)  return ; 
	   if(t->value == x)
	   {
	      bool d = t->c[1]->key < t->c[0]->key;  //两个字子节点
		  if(t->c[d] == null)
		  {
		    delete t; 
			t = null;
			return; 
		  }
		  rot(t,d);
		  Delete(t->c[!d],x);
	   }else{
	      bool d = x>t->value;
		  Delete(t->c[d],x);
	   }
	}
	void find(node *t  , int x){
	    if(t == null)
			return; 
		if(abs(x-t->value) < ans || (abs(x-t->value) == ans &&  t->value < x))
		{
		   ans = abs(x-t->value);
		   s = t->value;
		}
		if(x > t->value)
		{
		  find(t->c[1],x);
		}else{
		  find(t->c[0],x);
		}
	}
	public:
	treap(){
	  null = new node(0,0);
	  null ->size = 0 ; 
	  null ->key  = inf; 
	  root = null;
	}
	void ins(int x)
	{
	   insert(root , x);
	}
	void del(int x)
	{
	   Delete(root,x);
	}
	void fin(int x)
	{
	   find(root,x);
	}
	int isempty()
	{
	   if(root == null)
		   return 1; 
	   return 0;
	}
};
int main(){
   int n ; 
   scanf("%d",&n);
   int sum = 0  ;
   treap R,G;
   srand(time(NULL));
   for(int i = 1;i <= n;i ++)
   {
	  int st;
	  int x;  
	  scanf("%d %d",&st,&x);
	  ans = inf ; 
	  if(st == 0 )
	  {
         if(R.isempty()) 
		 {
		    G.ins(x);
		 }else{
		    R.fin(x);
			R.del(s);
	        sum = (sum + ans) % 1000000;
		//	printf("***%d\n",s);
		 }
	  }else {
	    if(G.isempty()) 
		{
	       R.ins(x);	
		}else{
		   G.fin(x);
		   G.del(s);
	       sum = (sum + ans) % 1000000;
		//   printf("***%d\n",s);
		}
	  }
   }
   printf("%d\n",sum);
return 0;
}
