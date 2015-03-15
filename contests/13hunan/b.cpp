// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年10月03日 星期五 13时30分42秒

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
#define maxn 100015
using namespace std;
struct node{
	int p;
	int isf;
	int head;
	int st,st1;
	int L[maxn],R[maxn],V[maxn];
	int hs[maxn];
	void init()
	{
		head = 0 ; 
		p = 0;  	
		isf = 0; 
	}
	void insert(int v)
	{
		p ++;
		L[p] = p-1;
		R[p-1] = p;
		V[p] = v; 
		hs[v] = p ; 
	}
	void change1(int v ,int v1)
	{
		st = hs[v];
		st1 = hs[v1];
		R[L[st]] = R[st];
	    L[R[st]] = L[st];
		L[st] = L[st1];
		R[st] = st1;
        R[L[st1]] = st;
		L[st1] = st; 
	}
	void change2(int v,int v1)
	{
		st = hs[v];
		st1 = hs[v1];
	    R[L[st]] = R[st];
	    L[R[st]] = L[st];
		L[st] = st1;
		R[st] = R[st1];
        L[R[st]] = st;
		R[st1] = st;
	}
	void change3(int v ,int v1)
	{
        st= hs[v];
		st1 = hs[v1];
        int tt; 
	    V[hs[v]] = v1;
		V[hs[v1]] = v;
		tt = hs[v];
		hs[v] = hs[v1];
		hs[v1] = tt;
	}
	void change4(int v,int v1)
	{
        isf = !isf;
	}
	LL query()
	{
	   LL sum = 0 ; 
	   bool iscount = 1; 
	   if(isf)
	   {
	      int next = L[0];
		  while(next)
		  {
		    //printf("%d ",V[next]);
		    if(iscount)
			{
			  sum += V[next];
			}
			iscount = !iscount;
			next = L[next];
		  }
	   }else {
	      int next = R[0];
		  while(next)
		  {
		    //printf("%d ",V[next]);
		    if(iscount)
			{
			  sum += V[next];
			}
			iscount = !iscount;
		    next = R[next];
		  }
	   }
	   //printf("\n");
	   return sum;
	}
}lst;

int main(){
	int n ,m ; 
	int ca = 0 ; 
	while(scanf("%d %d",&n,&m) != EOF)
	{
		ca ++;
		lst.init();
		int temp ; 
		
		for(int i = 1;i <= n;i ++)
		{
			lst.insert(i);
		}
		
		lst.L[0] = lst.p;
		lst.R[lst.p] = 0;
		for(int i = 1;i <= m;i ++)
		{
	      int a, b, c ;
         // lst.query();

		  scanf("%d",&a);
		  if(a ==  1)
		  {
			scanf("%d %d",&b,&c);
		    if(lst.isf)
			{
			   a = 2;
			}
		  }
		  else if(a == 2)
		  {
			scanf("%d %d",&b,&c);
		    if(lst.isf)
			{
			   a = 1;
			}
		  }
		  if(a == 1)
		  {
		    lst.change1(b,c);
		  }else if(a == 2){
		    lst.change2(b,c); 
		  }else if(a == 3){
			 scanf("%d %d",&b,&c);
		     lst.change3(b,c);
		  }else {
		     lst.change4(b,c);
		  }
		}
		printf("Case %d: %lld\n",ca,lst.query());
	}
	return 0;
}
