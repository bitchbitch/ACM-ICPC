// File Name: uva133.cpp
// Author: darkdream
// Created Time: 2013年04月27日 星期六 09时50分42秒

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
struct node
{
	int date;
	struct node *next ,*last;
};
int main(){
	int n,k,m;
	while(scanf("%d %d %d",&n,&k,&m) != EOF)
	{
		//k = k%(n+1); m = m%(n+1);
		if(n == 0)
			break;
		struct node *head,*p,*q;
		struct node a[30];
		for(int i = 1; i<= n;i ++)
		{  a[i].date = i;
			a[i].next = &a[i+1];
			a[i].last = &a[i-1];
		}
		a[1].last = &a[n];
		a[n].next = &a[1];
		p = &a[1];
		q = &a[n];
		while(1)
		{   
			
			if(n == 1)
			{ 
				printf("%3d\n",p->date);
				break;
			}
		   for(int i= 1; i< (k%n==0?n:k%n); i ++)
			{
				p = p->next;
			}
			for(int i = 1; i< (m%n==0?n:m%n) ; i++)
			{
				q = q->last;
			}
			if(p->next == q && p->last == q && p != q)
			{
			   printf("%3d%3d\n",p->date,q->date);
			   break;
			}
			if(p == q)
			{
			   
			    printf("%3d,",p->date);
			    p->next->last = p->last;
				p->last->next = p->next;
				p = p->next;
				q = q->last;
				n--;
               
			}
			else{
			  printf("%3d%3d,",p->date,q->date);
	          p->last->next = p->next;
			  p->next->last = p->last;
			  if(p->next == q)
				  p = q->next;
			  else
			    p= p->next;
			  q->last->next = q->next;
			  q->next->last = q->last;
			  q = q->last;
			  n = n-2;
			    
			}
	      	

		}


	}
	return 0;
}
