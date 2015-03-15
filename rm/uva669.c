// File Name: uva669.c
// Author: darkdream
// Created Time: 2013年05月21日 星期二 19时18分05秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int sum[10000];
struct node 
{
    int num;
	struct node* left,*right;
};
struct node *newnode()
{
    struct node *p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	return p;
}
void find(struct node*p,int k)
{
    if(p->num == -1)
	   return;
	sum[5000+k] += p->num;
	if(p->left != NULL)
	 find(p->left,k-1 );
	if(p->right != NULL)
	 find(p->right,k+1);

}

int main(){

  // freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int CASE = 0 ;
  
	while(1)
   {
	   CASE++;
	   memset(sum ,0,sizeof(sum));

      int temp ;
	  scanf("%d",&temp);
	  if(temp == -1)
		  break;
	  struct node *pnode[100000] = {0},*head;
	  pnode[1] = newnode();
	  pnode[1]->num = temp;
	  head = pnode[1];
	  int j = 1;

	  while(j != 0)
	  {
	     scanf("%d",&temp);
		 if(pnode[j]->left == NULL)
		 {
		   if(temp == -1)
		   {
			  pnode[j]->left = newnode();
			  pnode[j]->left->num = temp;
		   }
		   else
		   {
		     j++;
			 pnode[j] = newnode();
			 pnode[j]->num = temp;
			 pnode[j-1]->left = pnode[j];
		   }

		 }
		 else if(pnode[j]->right == NULL)
		 {
		   if(temp == -1)
		   {
			   pnode[j]->right = newnode();
			   pnode[j]->right->num = temp;
			   j = j -1;
			   if(j == 0)
				   break;
			   while(pnode[j]->right != NULL)
			   {
			     j = j-1;
				 if(j == 0)
					 break;
			   }
		   }
		   else
		   {
		      j++;
			  pnode[j] = newnode();
			  pnode[j]->num = temp ;
			  pnode[j-1]->right = pnode[j];

		   }
		 }
	  }

	  printf("Case %d:\n",CASE);
	  find(head,0);
	  int i = 0 ;
	  for(i = 0 ;i <=5000 ;i ++)
	    if(sum[i] !=  0)
			break;
	  for(int j = i ; j < 10000; j++)
	  {  
	     if(sum[j] == 0 )
			 break;
		 if(j != i)
		  printf(" ");
		 printf("%d",sum[j]);
	  }
	 printf("\n\n");
   }
return 0 ;
}
