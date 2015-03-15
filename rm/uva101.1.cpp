// File Name: uva101.cpp
// Author: darkdream
// Created Time: 2013年04月26日 星期五 19时55分53秒

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
struct point
{
   int date;
   struct point *next,*last;
};
struct point points[100];
int n ;
struct point *p ,*q;
int  find(int a, int b)
{
   int okq = 0;
   int okp = 0;
   for(int i = 0 ;i < n; i ++)
     {
		 if(points[i].next == NULL)
			 continue;

	     if(!okp)
		 {
		   p = points[i].next;
		   while(p != NULL)
		   {
		      if(p->date == a)
			  {
			    okp = i;
				break;
			  }
             p = p->next;
		   }
		 }
		 
		 
		 if(!okq)
		 {
		   q = points[i].next;
		   while(q != NULL)
		   {
		      if(q->date == b)
			  {
			    okq = i;
				break;
			  }
             q = q->next;
		   }
		 
		 }
		 if(okp && okq)
			 if(okp == okq)
				 return 0;
			 else 
				 return 1;
		
	 }
   return 0;
}
void op1(int a, int b)
{
  if(!find(a,b))
	  return;
  struct point *temp = NULL;
  temp = p->next;
  p->next = NULL;
  while(temp  != NULL)
  {
      points[temp->date].next = temp;
	  temp->last = &points[temp->date];
	  temp = temp->next;
	  if(temp != NULL)
	    temp->last->next = NULL;
  }
  temp = q->next;
  q->next = NULL;
  while(temp  != NULL)
  { 
      points[temp->date].next = temp;
	  temp->last = &points[temp->date];
	  temp = temp->next;
	  if(temp != NULL)
	    temp->last->next = NULL;
  }
  p->last->next = NULL;
  q->next = p;
  p->last = q;
   


}
void op2(int a,int b)
{
	if(!find(a,b))
		return;
  struct point *temp = NULL;
  temp = p->next;
  p->next = NULL;
  while(temp  != NULL)
  {
      points[temp->date].next = temp;
	  temp->last = &points[temp->date];
	  temp = temp->next;
	  if(temp != NULL)
	   temp->last->next = NULL;
  }
  while(q->next != NULL)
	  q = q->next;
  p->last->next = NULL;
  q->next = p;
  p->last = q;


}
void op3(int a, int b)
{
  if(!find(a,b))
	  return;
  struct point *temp = NULL;
  temp = q->next;
  while(temp  != NULL)
  {
      points[temp->date].next = temp;
	  temp->last = &points[temp->date];
	  temp = temp->next;
	  if(temp != NULL)
	  temp->last->next = NULL;
  }
  p->last->next = NULL;
  q->next = p;
  p->last = q;

}
void op4(int a,int b)
{
   if(!find(a,b))
	   return;
   while(q->next != NULL)
     q = q->next;	
	
  p->last->next = NULL;
  p->last = q;
  q->next = p;
  
}
void print()
{
   int i = 0 ;
   for(i = 0 ;i < n; i ++)
   {
      printf("%d:",i);
	  p = points[i].next;
	  while(p != NULL)
	  {
	    printf(" %d",p->date);
		p = p->next;
	  }
	 printf("\n");

   }
}
int main(){
   while(scanf("%d",&n) != EOF)

	{
	 memset(points,0,sizeof(points));
	 for(int i = 0 ;i < n; i ++)
	  {
		  points[i].last =  NULL;
		  points[i].date = -1;
	      points[i].next = (point*)malloc(sizeof(point));
		  points[i].next->date = i;
		  points[i].next->last = &points[i];
		  points[i].next->next = NULL;
	  }
      while(1)
	  {
	    char tempa[100],tempb[100];
		int a,b;
		scanf("%s",tempa);
		if(tempa[0] == 'q')
			break;

		scanf("%d %s %d",&a,tempb,&b);
		if((a == b) || (a < 0 || a>= n) ||(b <0 || b >= n))
			continue;
		if(tempa[0] == 'm' && tempb[1] == 'n')
			op1(a,b);
		if(tempa[0] == 'm' && tempb[1] == 'v')
			op2(a,b);
		if(tempa[0] == 'p' && tempb[1] == 'n')
			op3(a,b);
		if(tempa[0] == 'p' && tempb[1] == 'v')
			op4(a,b);
	  }
	  print();
	  free(p);
	  free(q);
   }
  
return 0;
}

