// File Name: 1.cpp
// Author: darkdream
// Created Time: 2014年07月12日 星期六 23时30分16秒

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

struct node{
    int num;
	int ok;
	int ok1;
	struct node *next[30];
};
struct node* newnode(){
   struct node * p = (node *)malloc(sizeof(node));
   for(int i =0 ;i < 30;i ++)
	   p->next[i] = NULL;
   p->ok = 0;
   p->num = 0  ;
   return p ; 
}
char str[100004];
int len ;
void build(struct node * p, int i )
{

   int k = str[i] -'a';
   if(i == len )
	   return ;
  if(p->next[k] == NULL)
   {
     struct node * t  = newnode();
	 t->num ++;
     p->next[k] =  t; 
	 build(p->next[k],i+1);
   }
  else {
	  p->next[k]->num += 1;
	  build(p->next[k],i+1);
   }
  int tok = 0 ;
  int nok = 0 ;
  int t1ok = 0 ;
  for(int i= 0;i < 30 ;i ++)
  {
     if(p->next[i] != NULL)
	 {
	    nok = 1; 
		if(p->next[i]->ok == 0 )
			tok = 1;
		if(p->next[i]->ok1 == 1)
            t1ok = 1;
	 }
  }
  if(!nok || tok)
	  p->ok = 1;
  else p->ok = 0;
  if(nok)
  {
	if(t1ok)
     p->ok1 = 0;
	else p->ok1 =1;
  }else{
     p->ok1 = 0;
  }
}
int ans;
void find(struct node * p, int i )
{
   int k = str[i] -'a';
   if(i == len )
	{
	  ans = p->num ;
	  return ; 
    }
   if(p->next[k] == NULL)
   {
	  return ; 
   }else find(p->next[k],i+1);
}
int main(){
    int n , k;

	struct node * head = newnode();
	scanf("%d %d",&n,&k);
	while(n --){
		 scanf("%s",str);
		 len = strlen(str);
		 build(head,0);
	}
   // printf("%d %d\n",head->ok,head->ok1);
	if(head->ok)
	{
	  if(!head->ok1)
	     printf("First\n");
	  else{
	    if(k % 2 == 1)
			printf("First\n");
		else printf("Second\n");
	  }
	}else{
       printf("Second\n"); 	
	}
return 0;
}

