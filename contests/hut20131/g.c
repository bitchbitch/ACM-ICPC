// File Name: g.c
// Author: darkdream
// Created Time: 2013年09月03日 星期二 16时02分52秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#define maxn  100005 
struct node2{
  int x, y,num;
}first[maxn],stack[maxn];
int pre[maxn];
int cmp1(const void * a,const void *b)
{
   if((*(node2*)a).x == (*(node2*)b).x)
   {
      return (*(node2*)b).y - (*(node2*)a).y;
   }
   else return (*(node2*)a).x - (*(node2*)b).x;
}
void print(int x)
{
  while(1)
  {
	printf("%d ",x);
	if(pre[x] == 0 )
	{	
	    return ;
	}
	x = pre[x];
	printf("%d ",x);
  }
	
}
int find(int flor,int y)
{
   int l = 1; 
   int r = flor;
   while(l <= r)
   {
	  int mid = (l+r)/2;
      if(stack[mid].y < y )
		  if(stack[mid].y >= y)
			  return mid + 1; 
	      else 
			  l = mid  +1;
	  else 
		  r = mid - 1;
   }
   return l;
}
void slove(int n)
{
   memset(pre,0,sizeof(pre));
   stack[0].y = 0 ;
   stack[0].x = 0 ;
   stack[0].num = 0;
   int flor = 0 ;
   for(int  i = 1;i <= n ;i ++)
   {
      if(first[i].y > stack[flor].y)
	  {
	     flor++;
		 stack[flor].y = first[i].y;
		 stack[flor].num = first[i].num;
		 stack[flor].x = first[i].x;
	     pre[first[i].num] = stack[flor-1].num;   
	  }
	  else {
	    int low = find(flor,first[i].y);
		stack[low].y = first[i].y ; 
		stack[low].num = first[i].num;
		stack[low].x = first[i].x;
		pre[first[i].num] = stack[low-1].num;
	  }

   }
   printf("%d\n",flor);
   print(stack[flor].num);
   printf("\n");   
   
}

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n;
   while(scanf("%d\n",&n) != EOF)
   {
	   for(int i = 1;i <= n;i ++)
	  { 
		scanf("%d %d",&first[i].x,&first[i].y);
	    first[i].num = i ; 
	  }
	  qsort(first+1,n,sizeof(node2),cmp1);
      slove(n);
   }
return 0 ;
}
