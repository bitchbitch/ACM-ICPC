// File Name: uva839.c
// Author: darkdream
// Created Time: 2013年05月22日 星期三 11时05分12秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node 
{
  int num;
  int length;
  struct node *left,*right;
};
struct node * newnode()
{
   struct node * p = (node*)malloc(sizeof(node));
   p->num = 0 ;
   p->length = 0 ;
   p->left = NULL;
   p->right = NULL;
   return p;
}
int  temp[100000][6],sub = 1;
void  buildtree(struct node *p)
{
   sub++;
   int k = sub;
   scanf("%d %d %d %d",&temp[sub][1], &temp[sub][2],&temp[sub][3],&temp[sub][4]);
   if(temp[k][1] == 0 )
   {
      p->left = newnode();
	  p->left->length = temp[k][2];
	  buildtree(p->left);
   }
    if(temp[k][1] != 0)
   {
     p->left = newnode();
	 p->left->num = temp[k][1];
	 p->left->length = temp[k][2];
   }
   if(temp[k][3] == 0 )
   {
      p->right = newnode();
	  p->right->length = temp[k][4];
	  buildtree(p->right);
   }
   if(temp[k][3] != 0)
   {
     p->right = newnode();
	 p->right->num = temp[k][3];
	 p->right->length = temp[k][4];
   }
   return ;
}
int ok = 1;
int  find(struct node *p)
{
	if(p->right == NULL&& p->left == NULL )
	{
	    return p->num*p->length;
	}
	if(find(p->right) != find(p->left))
	{
	 ok = 0;
	}
	p->num = p->right->num + p->left->num;
	return p->num*p->length;
 

}
void print(struct node *p)
{
   printf("%d ",p->num);
   if(p->left != NULL)
   {
     print(p->left);
	 print(p->right);
	 printf("\n");
   }
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n; 
   scanf("%d",&n);
   while(n--)
   {
	 ok = 1;
	 memset(temp,0,sizeof(temp));
      sub = 1;
	 struct node *head;
     head = newnode();
	 head->num = 0 ;
	 buildtree(head);
     find(head);
	 //print(head);
	 if(ok == 0 )
		 printf("NO\n");
	 else
		 printf("YES\n");
	 if(n != 0)
		 printf("\n");

   }
return 0 ;
}
