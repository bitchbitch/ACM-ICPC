// File Name: 4707.c
// Author: darkdream
// Created Time: 2013年09月08日 星期日 22时30分41秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
#define maxn 100006
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
struct node{
  int num ; 
  struct node * next ;
}list[maxn];
int visit[maxn];
struct node *newnode(int x){
   struct node * p = (node *)malloc(sizeof(node));
   p->num = x ; 
   p->next = NULL;
   return p ;
}
int sum = 0 ;
int n ,step;

void dfs(int x,int s)
{
   if(s > step)
	   sum ++;
   int k = list[x].num;
   struct node *p = list[x].next;
   for(int i = 1;i <= k;i ++)
   {
	  if(!visit[p->num] )
	  {
	    visit[p->num] = 1 ;
		dfs(p->num,s +1);
	  }
      p = p ->next;
   }
}
void mem( node * p )
{
   if(p->next != NULL)
	   mem(p->next);
   free(p);
}
int main(){
   int t; 
   scanf("%d",&t);
	while(t--)
	{

	 scanf("%d %d",&n,&step);
     memset(list,0,sizeof(list));
	 memset(visit,0,sizeof(visit));
	 sum = 0 ;
     int a, b ;
	 for(int i = 1;i < n; i++)
	 {
	   scanf("%d %d",&a,&b);
	   struct node *p = newnode(b);
	   list[a].num ++;
	   p->next = list[a].next;
	   list[a].next = p ;
	   p = newnode(a);
	   list[b].num ++;
	   p->next = list[b].next;
	   list[b].next = p;
	  }
	 visit[0] = 1;
	 dfs(0,0);
      
	 printf("%d\n",sum);
     for(int i = 0 ;i < n;i ++)
	 {
	   if(list[i].num != 0)
		   mem(list[i].next);
	 }
   }

return 0 ;
}
