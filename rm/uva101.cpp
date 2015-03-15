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

}
void op1(int a, int b)
{
  if(!find(a,b))
	  return;

  if(p->next == NULL)
  {
     p->last->next = NULL;
  }
  else
  {
     p->last->next = p->next;
	 p->next->last = p->last;
	 p->next = NULL;
  }
  while(q->next != NULL)
  {
    q = q->next;
  }
  p->last = q;
  q->next = p;

}
void op2(int a,int b)
{
	if(!find(a,b))
		return;
  if(p->next == NULL)
  {
     p->last->next = NULL;
  }
  else
  {
     p->last->next = p->next;
	 p->next->last = p->last;
	 p->next = NULL;
	
  }
  if(q->next == NULL)
  {
   p->last = q;
   q->next = p;
    
  }
  else
  {
    p->next = q->next;
	q->next->last = p;
    q->next = p;
	p->last = q;
  }


}
void op3(int a, int b)
{
  if(!find(a,b))
	  return;
  if(q->next == NULL)
  {
     p->last->next = NULL;
	 q->next = p;
	 p->last = q;
  }
  else
  {
     p->last->next = NULL;
     p->last = q;
	 struct point *temp = p;
	 while(temp->next != NULL)
	  {
	     temp = temp->next;
	  }
	 q->next->last = temp;
	 temp->next = q->next;
	 q->next = p;


  }

}
void op4(int a,int b)
{
   if(!find(a,b))
	   return;
   p->last->next = NULL;
   while(q->next != NULL)
   {
    q = q->next;
   }
   q->next = p;
   p->last = q;
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
			op2(a,b);
		if(tempa[0] == 'm' && tempb[1] == 'v')
			op1(a,b);
		if(tempa[0] == 'p' && tempb[1] == 'n')
			op3(a,b);
		if(tempa[0] == 'p' && tempb[1] == 'v')
			op4(a,b);

	  }
	  print();
   }
  
return 0;
}
