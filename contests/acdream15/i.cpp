// File Name: i.cpp
// Author: darkdream
// Created Time: 2014年07月04日 星期五 20时41分58秒

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
#include<queue>

using namespace std;
struct tnode{
	int num ; 
	int q,h;
	struct node * next;
};
struct node{
	char c;
	struct node* next;
	struct tnode* down; 
};
struct node * newnode(){
	struct node *p = (node *)malloc(sizeof(node));
	p->next = NULL; 
	p->down = NULL; 
	return p ; 
}
struct tnode *newtnode(){
	struct tnode *p = (tnode *)malloc(sizeof(tnode));
	p->h = 10000000;
	p->q = 0;
	p->num = 0 ; 
	p->next = NULL; 
	return p ; 
}
char str[1000005];
int len;
int ans ;
int push(struct tnode * head,int k)
{
	if(k == len)
	{
		ans  = min(head->q,head->h);
//		printf("%d %d\n",head->q,head->h);
		head->h = 1; 
		head->q = 1;
		return head->h + 1;
	}
	struct node * p = head->next ; 
	for(int i = 1;i <= head->num;i ++){
		if(p->c == str[k]){ 
			p->down->q = min(head->q+1,p->down->q);
			head->h = min(head->h,push(p->down,k +1));
			return head->h +1;
		}
		p = p ->next;
	}
	head->num ++ ; 
	p = newnode();

	p->c = str[k];
	p->next = head->next;
	head->next = p;

	struct tnode *temp = newtnode();
	p->down = newtnode();

	p->down->q = head->q +1;
	head->h = min(head->h,push(p->down,k +1));
	return head->h +1;
}
void F(struct tnode * head)
{
	struct node *p = head->next;
	while(p)
	{
		F(p->down);
		struct node *q = p ; 
		p = p ->next; 
		free(q);
	}
	free(head);

}
int main(){
	struct tnode *head = newtnode();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n ;
		scanf("%d",&n);
		struct tnode *head = newtnode();
		for(int i = 1;i <= n+ 1;i ++ )
		{
			scanf("%s",str);
			len = strlen(str);
			ans = 0 ; 
			push(head,0);
			if(i != 1)
				printf("%d\n",ans);
			//printf("%c\n",head->next->c);
		}
		F(head);
	}

	return 0;
}
