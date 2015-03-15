// File Name: 2tree.c
// Author: darkdream
// Created Time: 2013年03月21日 星期四 11时48分51秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char s[1000];
int failed = 0 ;

typedef struct Tnode{
   int have_value;
   int  v;
   struct Tnode * left , * right;
}node;
node *root;

void remove_tree(node *u)
{
  if(u == NULL)
	  return ;
  remove_tree(u->left);
  remove_tree(u->right);
  free(u);
}
node * newnode()
{
  node * u = (node *)malloc(sizeof(node));
  if(u !=NULL)
  {
      u->have_value =0 ;
	  u->left = u->right = NULL;
  }
  return u;
}
void addnode(int v, char *s)
{
  int n = strlen(s);
  node *u = root;
  for(int i = 0 ;i < n ;i ++)
  {
    if(s[i] == 'L')
	{	if(u->left == NULL)
		   u->left = newnode();
	  u = u->left ;
	}
	else if(s[i] == 'R')
	{
	   if(u->right == NULL)
		   u->right = newnode();
	   u = u->right;
	}
	
 
  }
  if(u->have_value) failed = 1;
  u->v = v ;
  u->have_value = 1;
}
int read_input()
{ 
   failed = 0;
   remove_tree(root);
   root = newnode();
   for(;;)
   {
      if(scanf("%s",s) != 1) return 0;
	  if(!strcmp(s,"()")) break;
	  int v;
	  sscanf(&s[1],"%d",&v);
	  addnode(v,strchr(s,',') +1);
	  printf("**\n");
   }
   return 1;

}
int ans[1000], n = 0 ;
int bfs()
{
   int front = 0 , rear  =1 ;
   node *q[1000];
   q[0] = root;
  while(front < rear)
  {
     node *u =q[front++];
     if(!u->have_value) return 0;
	 ans[n++] = u->v;
	 if(u->left != NULL) q[rear++] = u->left;
	 if(u->right != NULL) q[rear++] = u->right;

  }
  return 1;
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    if(read_input())
	{
      if(bfs())
	   {
       printf("%d",n);
       for(int i = 0 ;i < n; i ++ )
	   printf("%d ",ans[i]);
	    printf("\n");
	   }
	  else
		  printf("-1\n");
	}
return 0 ;
}
