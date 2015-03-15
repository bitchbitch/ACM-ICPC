// File Name: uva11234.c
// Author: darkdream
// Created Time: 2013年05月16日 星期四 19时18分02秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
struct node
{
  char c;
  struct node *right ,*left;
};
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t;
   scanf("%d\n",&t);
   while(t--)
   {
	 char str[10005];
     gets(str);
	 int k = strlen(str);
	 struct node nodes[10005];
	 struct node *hehe[10005],*head,*p;
     for(int i = 0; i < k ;i ++)
	 {
	    nodes[i].c = str[i];
		nodes[i].right = nodes[i].left  = NULL;
	 }
	 int j  = -1 ;
	 for(int i = 0 ;i < k; i ++)
	 {
		   j++;
		   hehe[j] = &nodes[i];
		if(isupper(hehe[j]->c))
		{
		    hehe[j]->right = hehe[j-2];
			hehe[j]->left = hehe[j-1];
			hehe[j-2] = hehe[j];
			hehe[j-1] = NULL;
			hehe[j] = NULL;
		   j = j -2;
		}
	 }
	int up = 1, low = 0;
	while(low < up)
	{
	   if(hehe[low]->right != NULL)
		hehe[up++] = hehe[low]->right;
	   if(hehe[low]->left != NULL)
		hehe[up++] = hehe[low]->left;
	   low++;
	}
	for(int i = up-1; i >= 0 ;i--)
		printf("%c",hehe[i]->c);
	printf("\n");
	 
   }
return 0 ;
}
