// File Name: uva10004.1.c
// Author: darkdream
// Created Time: 2013年06月15日 星期六 19时30分33秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[300][300];
int visit[300];
int ok, n ;
void dfs(int k , int sum)
{
  for(int i = 0;i < n; i++)
  {
    if(map[k][i] == 1 && visit[i]!= 0)
	{
       if(visit[i] == visit[k])
	   {
		   ok = 0;
		   return;
	   
	   }
	}
  }
  for(int i =0 ;i < n;i++)
  {
     if(map[k][i] && visit[i] == 0)
	 {
	    if(visit[k] == 1)
			visit[i] = 2;
		else
			visit[i] = 1;
		dfs(i,sum+1);
	 }
  }
}

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
	while(scanf("%d",&n) != EOF,n)
	{
	   ok = 1 ;
	   memset(map,0,sizeof(map));
	   memset(visit,0,sizeof(visit));
	   int m,a,b;
	   scanf("%d",&m);
	   while(m--)
	   {
	     scanf("%d %d",&a,&b);
         map[a][b] = 1 ;
		 map[b][a] = 1;
	   }
	   visit[0] = 1;
	   dfs(0,1);
	   /*for(int i = 0 ;i < n;i ++)
		   printf("%d ",visit[i]);
	   printf("\n");*/
	   if(ok)
		printf("BICOLORABLE.\n");
	   else
		printf("NOT BICOLORABLE.\n");
	}
	
return 0 ;
}
