// File Name: h.c
// Author: darkdream
// Created Time: 2013年07月23日 星期二 21时20分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int visit[100005];
struct node
{
   int x;
   struct node * next;
}list[100005];
struct node * newnode()
{
   struct node *p = (node *) malloc(sizeof(node));
   p->x = 1; 
   p->next = NULL;
}
int * newlist(int i)
{
   int *p = (int *) malloc(sizeof(int) * i);
}
int max = 0 ; 
int  dfs(int n)
{
  //printf("***%d\n",n);
  struct node * p = &list[n];
  int t = list[n].x;
  if(t == 0 )
	  return 1;
  int dmax = 0 ;
  for(int i =1 ;i<= t  ;i ++)
  {
     p = p->next;
	 if(visit[p->x] == 0 )
	 {
	   visit[p->x] = 1; 

	  int temp =  dfs(p->x);
	  if(temp  + dmax > max)
		 max = temp + dmax;
	  if(temp > dmax)
		 dmax = temp ;
	 }
  }
 return dmax+1;
  
}
int main(){


   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout); 
    int t;
	scanf("%d",&t);
	
	while(t --)
	{  max = 0 ;
       memset(visit,0,sizeof(visit));
	   memset(list,0,sizeof(list));
	   int n ; int m;
	   scanf("%d %d",&n,&m);
	     int a, b ;
	   for(int i =1 ;i <=n-1;i ++)
	   {
		 scanf("%d %d",&a,&b);
		 struct node * p =  newnode();
		 p->x = b;
		 p->next = list[a].next;
		 list[a].x ++;
		 list[a].next = p;
		 p = newnode();
		 p->x = a;
		 p->next = list[b].next;
		 list[b].next = p;
		 list[b].x ++;
	   }
	   visit[a] = 1; 
	   dfs(a);
	   //printf("%d\n",max);
	   while(m--)
	   {
	     int temp ;
		 scanf("%d",&temp);
		 if(temp <= max + 1)
		 {
		   printf("%d\n",temp -1);
		 }
		 else  if(temp <= n)
		 {
			printf("%d\n",max  + (temp - max -1)*2);
		 }

	   }

	}
return 0 ;
}
