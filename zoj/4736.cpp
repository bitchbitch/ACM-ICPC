// File Name: 4736.cpp
// Author: darkdream
// Created Time: 2014年07月23日 星期三 11时48分03秒

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
int ok = 1;
const int inf = ~0U>>1;
class treap{
	struct node{
		int value,key,size,num;
		node(int v , node *n):value(v)
		{c[0] = c[1] = n; size = 1;num = 1; key = rand()-1;}
		void rz(){size = c[0]->size + c[1]->size+ num;}
		node *c[2];
	}*root,*null;
	void rot(node *&t ,bool d)
	{
		node *c  =  t->c[d];
		t->c[d] = c->c[!d];
		c->c[!d] = t; 
		t->rz();
		c->rz();
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
			t->num++; 
			t->rz();
			return ;
		} 
		bool d = x > t->value;
		insert(t->c[d],x);
		if(t->c[d]->key < t->key)
			rot(t,d);
		else t->rz();
	}
	void Delete(node *&t,int x)
	{
		if(t == null)
	    {
		  ok = 0; 
		  return ;
		}
	//	printf("%d %d %d\n",x,t->value,t->num);
		if(t->value == x && t-> num != 1)
		{
			t->num -- ;
			t->rz();
			return ; 
		}
		if(t->value ==  x)
		{
			bool  d= t->c[1]->key  < t->c[0]->key;
			if(t->c[d] == null)
			{
				delete t; 
				t = null;
				return ;
			}
			rot(t,d);
			Delete(t->c[!d],x);
		}else {
			bool d = x > t->value;
			Delete(t->c[d],x);
		}
		t->rz(); //相当于pushup
	}
	void F(node *t)
	{
	   if(t == null)
		   return;
	   if(t->c[1] != null)
		   F(t->c[1]);
	   if(t->c[0] != null)
		   F(t->c[0]);
	   delete t;
	   t = null;
	}
	int select(node *t ,int k)
	{
		int r = t->c[0]->size;
		int l = t->c[0]->size + t->num;
		if(k > r && k <= l)
		{
			return t->value;
		}
		if(k <= r)  return select(t->c[0],k);
		return select(t->c[1],k-l);
	}
	public:
	treap()
	{
		null = new node(0,0);
		null->size = 0 ; 
		null->num = 0 ; 
		null->key = inf;
		root = null;
	}
	void ins(int x)
	{
		insert(root ,x);
	}
	void del(int x)
	{
		Delete(root,x);
	}
	void count()
	{
		//printf("%d\n",k);
		if(root == null ){
			printf("Empty!\n");
			return ;
		}
		int k = root->size;
		if(k % 2 == 1)
		{
			printf("%d\n",select(root,k/2+1));
		}else{
			LL temp = 1ll*select(root,k/2) + select(root,k/2+1);
		    if(temp % 2 == 0 )
				printf("%lld\n",temp/2);
			else printf("%.1f\n",temp*1.0/2);
		}
	}
	void free()
	{
	   F(root);
	}

};
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int ca; 
	scanf("%d",&ca);
	while(ca --)
	{
		int n ;
		scanf("%d",&n);
		treap T;
		for(int i =1 ;i <= n;i ++)
		{
			char str[10];
			int x;
			scanf("%s %d",str,&x);
			if(str[0] == 'r')
			{
				ok =1 ; 
				T.del(x);
				if(ok == 0 )
				{
					printf("Wrong!\n");
				}else{
					T.count();
				}
			}else{
				T.ins(x);
				T.count();
			}
		}
		T.free();
	}
	return 0;
}
