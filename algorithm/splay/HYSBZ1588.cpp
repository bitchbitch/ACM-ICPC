// File Name: spoj3468.cpp
// Author: darkdream
// Created Time: 2014年11月05日 星期三 19时40分26秒
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
using namespace std;
int ABS(int a)
{
   if(a < 0 )
	   return -a;
   return a;
}
	
struct Splaynode{
     struct node{
	    struct node *pre,*ch[2];
		int val; 
	 }*root;
	 node *newnode(int c)
	 {
	    node * p = (node*)malloc(sizeof(node));
	    p->pre = p->ch[0] = p->ch[1] = NULL;
		p->val = c;
		return p ;
	 }
	 void init(int c)
	 {
	   root = newnode(c);
	 }
     void Rotate(node *x ,int c)
	 {
	   node *y = x->pre;
	   //printf("%d %d\n",y->val,x->val);
	   y->ch[!c] = x->ch[c];
	   if(x->ch[c] != NULL)  x->ch[c]->pre = y; 
	   x->pre = y->pre;
	   if(y->pre != NULL)
	   {
	       if(y->pre->ch[0] == y) y->pre->ch[0] = x ;
		   else y->pre->ch[1] = x ; 
	   }
	   x->ch[c] = y,y->pre = x; 
	 }
	 void Splay(node *x ,node *f)
	 {
	   for(; x->pre != f ;)
	     if(x ->pre->pre == f)
		 { 
			 if(x->pre-> ch[0] == x)
			    Rotate(x,1);
		     else Rotate(x,0);
		 }else{
		    node *y = x->pre ,*z = y ->pre;
			if(z->ch[0] == y)
			{
		        if(y->ch[0] == x)
					Rotate(y,1),Rotate(x,1);
				else Rotate(x,0),Rotate(x,1);
			}else{
			    if(y->ch[1] == x)
					Rotate(y,0),Rotate(x,0);
				else
					Rotate(x,1),Rotate(x,0);
			}
		 }
	   if(f == NULL) root = x;
	 }
	 void Delet(node *&x)
	 {
		if(x == NULL)
			return;
		Delet(x->ch[0]);
		Delet(x->ch[1]);
        free(x);
		x = NULL;
	 }
	 void print(node *x)
	 {
		if(x == NULL)
			return;
	    print(x->ch[9]);
		printf("%d ",x->val);
		print(x->ch[1]);
	 }
	 int Rotateto(int v ,node *goal)
	 {
	     node *x  = root;
		 int mi = INT_MAX; 
		 while(1)
		 {
			// printf("***%d\n",x->val);
			 if(ABS(x->val - v) <mi)
				 mi = ABS(x->val - v); 
		     if(v > x->val)
			 {
				 if(x->ch[1] == NULL)
				 {
			         x->ch[1] = newnode(v);	 
		             x->ch[1]->pre = x; 
					 Splay(x->ch[1],goal);
				     return mi; 
				 }
			     x = x->ch[1];
			 }else if(v < x->val){
				 if(x->ch[0] == NULL)
				 {
			         x->ch[0] = newnode(v);	 
		             x->ch[0]->pre = x; 
					 Splay(x->ch[0],goal);
					 return mi ; 
				 }
			     x = x->ch[0]; 
			 }else return 0 ; 
		 }
		 return mi; 
	 }

}sp;

int main(){
    int n ;
    	scanf("%d",&n);
		if (n == 0 )
		{
			printf("0\n");
         return 0 ; 
		}
		int v ; 
		scanf("%d",&v);
		int ans = v; 
		sp.init(v);
		for(int i = 1;i < n;i ++)
		{
			scanf("%d",&v);
			ans += sp.Rotateto(v,NULL);
		}
		printf("%d\n",ans);
	return 0;
}
