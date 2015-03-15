// File Name: uva10557.c
// Author: darkdream
// Created Time: 2013年06月01日 星期六 20时10分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
struct point
{
	int value;
	int k; 
	int a[103];
}points[105];

struct node
{
  int v ;
  int t ;
}list[1000000];
int begin,end,ok ,n;
int visit[105];
int canvisit[105];
void dfs(int p)
{
	if(p == n)
	 {
	  ok = 1;
	  return;
	 }
   for(int i =1; i <= points[p].k ; i ++)
   {
	 int temp = points[p].a[i];
     if(canvisit[temp])
	 {
	    canvisit[temp] = 0 ;
		dfs(temp);
	 }
   }

}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	while(scanf("%d",&n) != EOF)
	{
		if(n == -1)
			break;
		begin = 0 ;
		end = 0 ;
		ok = 0 ;
		memset(points,0,sizeof(points));
		memset(visit,0,sizeof(visit));
		memset(canvisit,0,sizeof(canvisit));
		for(int i =1 ;i <= 100 ;i ++)
			canvisit[i] = 1;
		for(int i = 1; i <= n;i ++)
		{

			scanf("%d %d",&points[i].value,&points[i].k);
			for(int j =1 ;j <= points[i].k;j ++)
			{
				scanf("%d",&points[i].a[j]);
			}
		}
        list[1].t = 1; 
		list[1].v = 100;
		visit[1] = 1;
		int low = 1, high = 1;
		while(low <= high)
		{
		  //printf("%d\n",low);
		  if(list[low].t == n)
		  {
		   ok = 1; 
		   break;
		  }
		  if(ok)
			  break;
		 int temp = list[low].v + points[list[low].t].value;
		 if(temp <= 0 )
		 {
		   low++;
		   continue;
		 }
		  for(int i = 1; i <= points[list[low].t].k ;i ++)
		  {
			 int p = points[list[low].t].a[i];
		     if(canvisit[p] )
			 {
				 //printf("%d\n",p);
			     if(!visit[p])
				 {
                   visit[p] = 1;
				   high++;
				   list[high].t = p;
				   list[high].v = temp;
				 }
				 else
				 {
				     if(temp > list[p].v)
					 {
					   canvisit[p] = 0;
					   dfs(p);
					 }
				 }
			 }
		  }
		  low++;
		}
		if(!ok)
			printf("hopeless\n");
		else
			printf("winnable\n");
	}
	return 0 ;
}
