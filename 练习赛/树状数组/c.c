// File Name: c.c
// Author: darkdream
// Created Time: 2013年03月22日 星期五 14时00分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef struct tnode
{
   int v , ok;
   struct tnode * next;
}heihei;
typedef struct hashs 
{
  int k;
  struct tnode *next ;
  
}hash;

heihei* newnode(){
    heihei * u = (heihei *)malloc(sizeof(heihei));
	if(u!= NULL)
	{
	  u->ok = 0 ;
	  u->v = 0 ;
	  u->next = NULL;
	}
  return u;
}
int main(){
   
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int n ;
	hash t[23000];
	int  m[23001];
    while(scanf("%d",&n) != EOF)
	{
	   memset(t,0,sizeof(t));
	   char a[10];
	   int temp;
	   getchar();
	   for(int i = 1 ;i <= n; i ++)
	   {
		 int temp = 1;
	     scanf("%s %d\n",a,temp);
	     
	   }
	}
return 0 ;
}
