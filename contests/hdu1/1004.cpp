// File Name: 1004.cpp
// Author: darkdream
// Created Time: 2014年07月29日 星期二 09时51分07秒

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
#define LL long long 
int fm;
int ok;
const int inf = ~0U>>1;
class treap
{
   struct node{
       int value , key ,num;
	   node (int v, node *n):value(v)
	   {
	     c[0] = c[1] = n ;num = 1 ;  key = rand()-1;
	   }
	   node *c[2];
   }*root ,*null;
   void rot(node *&t , bool d)
   {
      node *c = t->c[d];
	  t->c[d] = c->c[!d];
	  c->c[!d] = t; 
	  t = c; 
   }
   void insert(node *&t ,int x)
   {
     if(t == null)
	 {
	    t= new node(x,null);
		return ;
	 }
	 if(x == t->value){
	    t->num ++ ; 
	    return ;
	 }
	 bool d = x > t->value;
	 insert(t->c[d],x);	
	 if(t->c[d]->key < t->key)
		 rot(t,d);
   }
   void Delete(node *&t ,int x)
   {
       if(t == null)
	   {
	    ok = 0 ; 
		return ; 
	   }
	   if(t->value == x && t->num != 1)
	   {
		  //printf("2*****");
	      t->num -- ; 
		  return ; 
	   }
	   if(t->value  == x)
	   {
		 // printf("1*****");
	      bool d = t->c[1]->key < t->c[0]->key;
		  if(t->c[d] == null)
		  {
		    delete t; 
			t = null ; 
			return ; 
		  }
		  rot(t,d);
		  Delete(t->c[!d],x);
	   }else{
	     bool d  = x > t->value; 
		 Delete(t->c[d],x);
	   }
   }
   void find(node *t , int x)
   {
	    if(t == null)
			return ;
	   // printf("%d**\n",t->value);
        if(t->value >= x)
		{
	      	ok = 1; 
			fm = min(fm,t->value);
            find(t->c[0],x);
		}else{
		    find(t->c[1],x);
		}
   }
   void Free(node *t)
   {
       if(t == null)
		   return ;;
	   if(t->c[1] != null)
		   Free(t->c[1]);
	   if(t->c[0] != null)
		   Free(t->c[0]);
	   delete t ;
	   t = null;
   }
	public:
	   treap()
	   {
	      null = new node(0,0);
		  null->num = 0 ; 
		  null->key = inf;
		  root = null;
	   }
	   void ins(int x)
	   {
	      insert(root,x);
	   }
	   void del(int x)
	   {
	      Delete(root ,x);
	   }
	   void   f(int x)
	   {
		   find(root,x);
	   }
	   void fre()
	   {
	      Free(root);
	   }

};
struct node1{
  int x, y ; 
}K[100005];
bool cmp(node1 x, node1 y)
{
	if(x.x == y.x)
       return x.y > y.y;
    return x.x > y.x ; 
}
int main(){
   int n , m; 
   while(scanf("%d %d",&n,&m) != EOF)
   {
	    treap T[104];
        for(int i =1 ;i <= n;i ++)
		{
	       int a, b ; 
		   scanf("%d %d",&a,&b);
		   T[b].ins(a);
		}
		int num  = 0 ; 
		LL sum = 0 ;
        for(int i =1 ;i <= m;i ++)
		{
		   scanf("%d %d",&K[i].x,&K[i].y);
		}
		sort(K+1,K+1+m,cmp);
		for(int i =1;i <= m;i ++){
		   int a, b; 
		   a = K[i].x;
		   b = K[i].y;
		   for(int j = b ;j <= 100;j ++)
		   {
			  ok = 0 ;
			  fm = 1e9;
		      T[j].f(a);
			 // printf("%d %d\n",fm,ok);
			  if(ok == 1)
			  {
			     T[j].del(fm);
				 sum += 500*a+2*b ;
				 num ++ ; 
				 break;
			  }
		   }
		}
	//	for(int i =1 ;i <= 100 ;i ++)
	//		T[i].fre();
		printf("%d %I64d\n",num,sum);
   }
return 0;
}
