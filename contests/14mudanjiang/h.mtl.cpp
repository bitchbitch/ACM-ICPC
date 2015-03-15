// File Name: h.cpp
// Author: darkdream
// Created Time: 2014年10月18日 星期六 11时35分02秒

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
//#define debug
#ifdef debug

#endif
using namespace std;
char str[600005];
char str1[600005];
int len; 
int sp;
int change(char c)
{
   if(c >= 'a' && c <= 'z')
	   return c- 'a';
   if(c >= 'A' && c <= 'Z')
	   return c - 'A' + 26;
   if(c >= '0' && c <= '9')
	   return c - '0' + 52;
}
struct Trie{
	struct node{
	   struct node * ne[63];
	   struct node * fa;
	   struct Trie * sub;
	   int iss;
	   int isend;
	   int be;
	   int en;
	}; 
    struct node* newnode()
	{
       struct node* p  = (node*)malloc(sizeof(node));
	   for(int i = 0 ;i < 63 ;i ++)
		   p->ne[i] = NULL;
	    p->fa =NULL;
	    p->sub = NULL;
		p->isend = 0 ;
		p->be = 0 ; 
		p->en = 0 ;
		return p ;
	}
	struct node * root ; 
	
	void init()
	{
       root = newnode();
	}
	struct Trie *newTrie()
	{
       struct Trie* p  = (Trie*)malloc(sizeof(Trie));
	   p->init();
	   return p ;
	}
	void freenode(node * p)
    {
	   for(int i = 0 ;i < 63;i ++)
	   {
	       if(p->ne[i] != NULL)
		   {
		      if(p->sub!= NULL)
			  {
				  p->sub->freenode(p->sub->root);
			      free(p->sub);
			  }
			  freenode(p->ne[i]);
		   }
	   }
      free(p);
	}
    void insert()
	{
	  //struct node *now = root;
	  int be = sp;
#ifdef debug
			  printf("%c%c%c\n",str[sp-1],str[sp],str[sp+1]);
#endif
	  while(be < len)
	  {
		  //printf("*******");
		  if(str[be+1] == '}')
		  {
		    sp = be + 1;
			return;;
		  }
		  int i ;
		  be = be + 3;
		  if(be + 3 >= len)
			  return;
		  
		  struct node *now = root;
		  for(i = be ;str[i] !='"';i ++)
		  {
#ifdef debug
			  printf("%c",str[i]);
#endif
			  int tt = change(str[i]);

			  if(now->ne[tt] == NULL)
			  {
				  now->ne[tt] = newnode();
			  }
			  now = now->ne[tt];
		  }
	      now->isend = 1;
		  //printf("%c\n",str[i+2]);
		  if(str[i+2] == '"')
		  {
			 now->be = i + 2;
			 now->iss = 1; 
		     int j = i + 3;   
			 while(str[j] != '"')
			 {
			   j++ ; 
			 }
			 now->en = j;
		     be = j; 
		  }else{
			sp = i + 1;
			now->be = i + 2;
		    now->sub = newTrie();
			now->sub->insert();
			be = sp;
			now->en = be;
		  }
#ifdef debug
		  printf("\n%d %d\n",now->be,now->en);
		 /*   for(int i = now->be ;i <= now->en;i ++)
				printf("%c",str[i]);
			printf("\n");*/
#endif
	  }
      sp = be;
	}
    

	void query()
	{
	//	debug(root);
		struct node *now = root;
		int i ;
#ifdef debug
			  printf("%d %c\n",sp,str1[sp]);
#endif
		for(i = sp;str1[i] != '"'  ;i ++)
		{
#ifdef debug
     		printf("%c",str1[i]);
#endif
			int tt = change(str1[i]);
			if(now->ne[tt] != NULL)
			{
				now = now->ne[tt];	
			}else {
				//printf("%d\n",i);
				printf("Error!\n");
				return;
			}
		}  
#ifdef debug
		printf("\n**********8\n");
#endif
		sp = i + 3; 
		if(now->isend == 0)
		{ 
			printf("Error!\n");
			return;
		}
		if(sp >= len)
		{
			//printf("%d %d\n",now->be,now->en);
		    for(int i = now->be ;i <= now->en;i ++)
				printf("%c",str[i]);
			printf("\n");
		}else{
			if(now->sub == NULL)
			{
				printf("Error!\n");
			    return;
			}
			now->sub->query();
		}
	}
};
Trie root;
int main(){
    //freopen("test.in","r",stdin);
	int t; 
	scanf("%d",&t);
	int kt =  0 ; 
	while(t--)
	{
	  kt ++ ; 
	  if(kt >= 5)
		 break;
      scanf("%s",str);
	 // printf("%ld\n",sizeof(root.root));
	  //puts("input is suc");
	  len = strlen(str);
	  sp = -1; 
	  root.init();
	  //puts("init is suc");
	  root.insert();
	  //root.debug(root.root);
	  int q; 
	  scanf("%d",&q);
	  for(int i = 1;i <= q;i ++)
	  {
	     scanf("%s",str1);
		 sp = 1; 
		 len = strlen(str1);
		 root.query();
	  }
	  root.freenode(root.root);
	}
return 0;
}
