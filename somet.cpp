// File Name: somet.cpp
// Author: darkdream
// Created Time: 2013年12月18日 星期三 13时19分15秒

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
struct Linkedlist{
   int data;
   struct Linkedlist * next;
}A,B,*p,*q,*pre,*u;
void Difference(Linkedlist A,Linkedlist B,Linkedlist *n)
{p=A.next;
	q=B.next;  pre=&A;
	while (p!=NULL&&q!=NULL)
		if(p->data<q->data)
		{
			pre=p;
			p=p->next;
			*n++;
		}
		else if(p->data>q->data)
			q=q->next;
		else{pre->next=p->next;
			u=p; p=p->next;delete u;
		}
}
int main(){

		return 0;
	}
