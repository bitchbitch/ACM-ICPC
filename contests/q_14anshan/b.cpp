// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年10月22日 星期三 15时51分59秒

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
struct node{
   int x;
   LL v ;
   int ne , la; 
}a[6004];
char str[10];
int first;
int last ;
int top = 0 ;
void print()
{
   for(int i = a[0].ne;i  != 6000 ;i = a[i].ne)
   {
     printf("%d %lld\n",a[i].x, a[i].v);
   }
}
int find(int x)
{
   //printf("%d\n",a[0].ne);
   for(int i = a[0].ne;i  != 6000 ;i = a[i].ne)
   {
       if(a[i].x == x)
		   return i ;
   }
   return 0 ; 
}
int L;
void add(int x )
{
   if(find(x))
   {
     printf("same priority.\n");
   }else {
     printf("success.\n");
	 L ++ ;
	 a[L].x = x; 
	 a[L].v = 0 ; 
	 a[L].ne = last;
	 a[L].la = a[last].la;
	 a[a[last].la].ne = L;
	 a[last].la = L; 
   }
}
void chat(int x)
{
   if(a[first].ne == 6000)
   {
      printf("empty.\n");
	  return;
   }
   printf("success.\n");
   if(top)
   {
      a[top].v += x;   
   }else {
       a[a[first].ne].v += x; 
   }
}
void close(int x)
{
   int k = find(x);
   if(k)
   {
	  printf("close %d with %lld.\n",a[k].x,a[k].v);
      a[a[k].la].ne = a[k].ne;
	  a[a[k].ne].la = a[k].la;
	  if(a[k].x == top)
	  {
	    top = 0 ; 
	  }
   }else {
     printf("invalid priority.\n");
   }
}
void rotata(int x)
{
   int t = 1 ; 
   for(int i = a[first].ne ;i != last;i = a[i].ne)
   {
	   if(t == x)
	   {
		   a[a[i].la].ne = a[i].ne;
		   a[a[i].ne].la = a[i].la;
		   
		   a[i].ne = a[first].ne;
		   a[i].la = first;
		   a[a[first].ne].la = i;
		   a[first].ne = i; 
		   printf("success.\n");
	       return;
	   }
	   t ++;
   }
   printf("out of range.\n");
}
void Prior()
{
   if(a[first].ne == last)
   {
     printf("empty.\n");
	 return;
   }
   int mx = 0 ; 
   int site = 0;
   for(int i = a[first].ne ;i != last;i = a[i].ne)
   {
      if(a[i].x  > mx)
	  {
	     site = i ; 
		 mx = a[i].x; 
	  }
   }
		   a[a[site].la].ne = a[site].ne;
		   a[a[site].ne].la = a[site].la;
		   
		   a[site].ne = a[first].ne;
		   a[site].la = first;
		   a[a[first].ne].la = site;
		   a[first].ne = site; 
   printf("success.\n") ;  
}
void  choose(int x)
{
    int site = find(x);
	if(site == 0 )
	{
	  printf("invalid priority.\n");
	  return;
	}
		   a[a[site].la].ne = a[site].ne;
		   a[a[site].ne].la = a[site].la;
		   
		   a[site].ne = a[first].ne;
		   a[site].la = first;
		   a[a[first].ne].la = site;
		   a[first].ne = site; 
   printf("success.\n") ;  
}
void Top(int x)
{
    int site = find(x);
	if(site == 0 )
	{
	  printf("invalid priority.\n");
	  return;
	}
    top = site;
	printf("success.\n") ;  
}
void Untop()
{
   if(top == 0 )
   {
     printf("no such person.\n");
	 return;
   }
   top = 0 ; 
	printf("success.\n") ;  
}
void say()
{
  if(top)
  {
   if(a[top].v != 0 )
     printf("Bye %d: %lld\n",a[top].x,a[top].v);
  }
  for(int i = a[0].ne;i != last;i  = a[i].ne)
  {
	if(i != top && a[i].v != 0 )
     printf("Bye %d: %lld\n",a[i].x,a[i].v);
  }
}
int main(){
    int t; 
	scanf("%d",&t);
    while(t--)
	{
	  int n ;
	  memset(a,0,sizeof(a));
	  scanf("%d",&n);
	  a[0].ne = 6000 ; 
	  a[0].la = 6000; 
	  a[6000].ne = 0;
	  a[6000].la = 0;
	  first = 0 ; 
	  last = 6000;
	  top = 0 ; 
	  int tmp;
	  L = 0 ; 
	  for(int i = 1;i <= n;i ++)
	  {
	      scanf("%s",str);
		  printf("Operation #%d: ",i);
		  if(str[0] == 'A')
		  {
		    scanf("%d",&tmp) ;
			add(tmp);
		  }else if(str[0] == 'C' && str[1] == 'l')
		  {
		    scanf("%d",&tmp);
			close(tmp);	
		  }else if(str[0] == 'C' && str[1] == 'h' && str[2] == 'a')
		  {
		    scanf("%d",&tmp);
			chat(tmp);	
		  }else if(str[0] == 'R' && str[1] == 'o')
		  {
		    scanf("%d",&tmp);
			rotata(tmp);	
		  }else if(str[0] == 'P' && str[1] == 'r')
		  {
		     Prior();
		  }else if(str[0] == 'C' && str[1] == 'h' && str[2] == 'o')
		  {
		     scanf("%d",&tmp);
			 choose(tmp);
		  }else if(str[0] == 'T')
		  {
		      scanf("%d",&tmp);
			  Top(tmp);
		  }else{
		     Untop();
		  }
		  //print();
	  }
	  say();
	}
	return 0;
}
