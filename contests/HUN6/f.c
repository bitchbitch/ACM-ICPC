// File Name: f.c
// Author: darkdream
// Created Time: 2013年07月20日 星期六 09时35分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
struct node 
{
   int x,y,num;
}list[100005];
int cmp(const void *a ,const void *b)
{
    if((*(node *)a).y != (*(node *)b ).y)
     return (*(node *) a).y - (*(node *)a ).y;
	else 
		return (*(node *)a ).x -(*(node *)b).x;
}
int cmp1(const void * a ,const void * b)
{
   return (*(node *)a).x - (*(node * )b).x;
}
int ans[100005];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n; 
   while(scanf("%d",&n) != EOF)
   {
	 memset(list,0,sizeof(list));
	 memset(ans,0,sizeof(ans));
     for(int i = 1;i<= n;i ++)
	 { 
	   list[i].num = i;
	   scanf("%d %d",&list[i].x,&list[i].y);
	 }
	 qsort(list+1,n,sizeof(node),cmp);
	 int k = 1;
	 int t  = 0 ; 
	 for(int i= 2;i <= n;i ++)
	 {
          if(list[i].x >= list[k].y)
		  {
		    t ++;
			ans[t] = i-1;
			k = i ;
		  }
	 }
	 t++;
	 ans[t] = n;
	 int p = 0; 
	 for(int i = 1 ;i <= t; i ++)
	 {
		 qsort(list + p + 1,ans[t] - p,sizeof(node),cmp1);
		 p = ans[t];
	 }
	 printf("%d\n",t);
	 for(int i = 1;i <= t;i ++)
	 {
	    for(int j = ans[i-1]+ 1; j <= ans[i]; j++)
			printf(j == ans[i-1] + 1?"%d":" %d",list[j].num);
		printf("\n");
	 }
	printf("\n");
   }
return 0 ;
}
