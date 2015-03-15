// File Name: treap.cpp
// Author: darkdream
// Created Time: 2014年07月22日 星期二 09时06分23秒

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
int mi = 1e9 ; 
class treap
{
	struct node{
		int value , key ,size;
		node(int v, node *n):value(v)
		{c[0] = c[1]= n; size = 1; key = rand()-1;}
		void rz(){size =c[0]->size + c[1]->size+1;}
		node*c[2];
	}*root,*null;
	void rot(node *&t,bool d)
	{
		node *c = t->c[d];
		t->c[d] = c->c[!d];
		c->c[!d] = t; 
		t->rz();c->rz();
		t = c;
	}
	void insert(node *&t,int x)
	{
		if(t == null)
		{
			t = new node(x,null);
			return ; 
		}
		if(x == t->value) return;
		bool d = x > t->value;
		insert(t->c[d],x);
		if(t->c[d]->key < t->key) //把小的随机值移动到上面
			rot(t,d);
		else t->rz();
	}
	void Delete(node *&t,int x)
	{
		if(t == null) return;
		if(t->value == x)  //將这个值一直旋转到叶子节点然后删除
		{
			bool d = t->c[1]->key < t->c[0]->key;
			if(t->c[d] == null)
			{
				delete t;
				t = null;
				return ;
			}
			rot(t,d);
			Delete(t->c[!d],x);
		}
		else{
			bool d = x>t->value;
			Delete(t->c[d],x);
		}
		t->rz();
	}
	int select(node *t ,int k )
	{
		int r = t->c[0]->size;
		if(k ==  r)
			return t->value;
		if(k < r) return select(t->c[0],k);
		return select(t->c[1], k - r - 1);
	}
	int rank(node *t , int x)
	{
		if(t == null) return 0 ; 
		int r = t->c[0]->size;
		if(x == t->value)
			return r;
		if(x < t->value)  return rank(t->c[0],x);
		return r+1+rank(t->c[1],x);
	}
	void  find(node *t, int x )
	{
		if(t == null)
			return ;
		mi = min(abs(x-t->value),mi);
		if(x > t->value)
			find(t->c[1],x);
		else find(t->c[0],x);
	}
	public:
	treap()
	{
		null = new node(0,0);
		null ->size = 0 ;
		null ->key = inf;
		root = null;
	}
	void ins(int x)
	{
		insert(root,x);
	}
	int sel(int k)
	{
		if(k > root->size) return -inf;
		return select(root,k-1);
	}
	int ran(int x)
	{
		return rank(root,x);
	}
	void del(int x)
	{
		Delete(root,x);
	}
	void fin(int x)
	{
		find(root,x); 
	}
};
int main(){
	//printf("%d\n",inf);   
	//freopen("in","r",stdin);
	int m ; 
	scanf("%d",&m);
	srand(time(NULL));
	// printf("****\n");
	treap T;
	int temp ; 
	scanf("%d",&temp);
	long long  sum = temp ;
	T.ins(temp);
	for(int i = 1 ;i < m;i ++)
	{
		scanf("%d",&temp);
		mi = 1e9;
		T.fin(temp);
		T.ins(temp);
		sum += mi;
	//	printf("****\n");
	}
	printf("%lld\n",sum);
	return 0;
}
