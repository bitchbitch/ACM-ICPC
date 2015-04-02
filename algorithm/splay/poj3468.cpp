// File Name: spoj3468.cpp
// Author: darkdream
// Created Time: 2014年11月05日 星期三 19时40分26秒

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
int num[maxn];
struct Splaynode{
     struct node{
	    struct node *pre,*ch[2];
	    LL add;
		LL sum; 
		LL val; 
		LL size;
	 }*root;
	 node *newnode(int c)
	 {
	    node * p = (node*)malloc(sizeof(node));
	    p->pre = p->ch[0] = p->ch[1] = NULL;
		p->sum = p->val = c ;
		p->size = 1 ; 
		p->add = 0 ;
		return p ;
	 }
	 void push_down(node *x)
	 {
		//printf("push_down***%lld\n",x->val);
	    x->val += x->add;
	    if(x->ch[0] != NULL)
		{
		   x->ch[0]->sum += x->ch[0]->size * x->add;
		   x->ch[0]->add += x->add;
		}
		if(x->ch[1] != NULL)
		{
		   x->ch[1]->sum += x->ch[1]->size * x->add;
		   x->ch[1]->add += x->add;
		}
		x->add = 0 ; 
	 }
	 void push_up(node *x)
	 {
		x->size = 1;
		x->sum = x->val + x->add; 
	    if(x->ch[0] != NULL)
		{
	       x->size += x->ch[0]->size; 
		   x->sum += x->ch[0]->sum;
		}
		if(x->ch[1] != NULL)
		{
		   x->size += x->ch[1]->size;
		   x->sum += x->ch[1]->sum;
		}
	 }
	 void print(node *x)
	 {
		 if(x == NULL)
			 return;
		 print(x->ch[0]);
		 printf("%lld(%lld) ",x->val,x->sum);
		 print(x->ch[1]);
		 push_up(x);
	 }
	 void build(node *&x ,int l , int r ,node *f) //这里需要传递一个引用
	 {
	   if(l > r )
		   return ; 
	   int m = (l + r )  >> 1; 
	   x = newnode(num[m]);
	   build(x->ch[0],l,m-1,x);
	   build(x->ch[1],m+1,r,x);
	   x->pre = f ;
	   push_up(x);
	 }
	 void init(int n)
	 {
	   root = NULL;
	   root = newnode(-1);
       root->ch[1]=newnode(-1);
       root->ch[1]->pre = root;
	   root->size = 2;
	   for(int i = 1;i <= n;i ++)
	     scanf("%d",&num[i]);
	   build(root->ch[1]->ch[0],1,n,root->ch[1]);
	   push_up(root->ch[1]);
	   push_up(root);
	 }
     void Rotate(node *x ,int c)
	 {
	   node *y = x->pre;
	   //printf("%lld %lld\n",y->val,x->val);
       push_down(y);
	   push_down(x);
	   y->ch[!c] = x->ch[c];
	   if(x->ch[c] != NULL)  x->ch[c]->pre = y; 
	   x->pre = y->pre;
	   if(y->pre != NULL)
	   {
	       if(y->pre->ch[0] == y) y->pre->ch[0] = x ;
		   else y->pre->ch[1] = x ; 
	   }
	   x->ch[c] = y,y->pre = x; 
	   push_up(y);
	 }
     void Delete(node *x)
	 {
	     if(x == NULL)
			 return;
		 Delete(x->ch[0]);
		 Delete(x->ch[1]);
		 //printf("%lld\n",x->val);
		 free(x);
		 x = NULL;
		 if(x != NULL)
			 printf("****\n");
		 //x = NULL;
		 //printf("%lld\n",x->val);
	 }
	 void Splay(node *x ,node *f)
	 {
	   //printf("****\n");
	   push_down(x); //为何要push_down
	  // printf("****\n");
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
	   push_up(x);
	   if(f == NULL) root = x;
	 }
	 void Rotateto(int k ,node *goal)
	 {
	     node *x  = root;
		 push_down(x);
		 while(1)
		 {
			if((x->ch[0] == NULL &&k == 0) || (x->ch[0]!= NULL && x->ch[0]->size == k))
				break;
		    if(x->ch[0] !=NULL && k < x->ch[0]->size)
			{
			    x = x->ch[0];
			}else{
		        k -= ((!x->ch[0])?1:x->ch[0]->size+1); 
			    x = x->ch[1];
			}
		    push_down(x);
   //		printf("%lld %lld %d\n",x->val,x->size,k);
		 }
		// printf("****\n");
		 //printf("%lld\n",x->pre->val);
         Splay(x,goal);
	 }
	 void update()
	 {
	    int l , r, c; 
		scanf("%d %d %d",&l,&r,&c);
		Rotateto(l-1,NULL);
		Rotateto(r+1,root);
        root->ch[1]->ch[0]->add += c; 
        root->ch[1]->ch[0]->sum += root->ch[1]->ch[0]->size * c; 
	 }
	 void query()
	 {
	   int l , r; 
       scanf("%d %d",&l,&r);
	   Rotateto(l-1,NULL);
	//   print(root);
	  // printf("\n");
	   Rotateto(r+1,root);
	  // print(root);
	  // printf("\n");
	  // printf("****\n");
	   printf("%lld\n",root->ch[1]->ch[0]->sum);
	 }

}sp;

int main(){
    int n ,m;
	scanf("%d %d",&n,&m);
	sp.init(n);    
	//sp.print(sp.root);;
//	printf("\n");
	while(m--)
	{
	   char op[10];
	   scanf("%s",op);
	   if(op[0] == 'Q')
	   {
	      sp.query();
	   }else {
	      sp.update();
	   }
	}
//	while()
	return 0;
}
