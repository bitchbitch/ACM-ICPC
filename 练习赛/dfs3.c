// File Name: dfs3.c
// Author: darkdream
// Created Time: 2013年03月14日 星期四 13时48分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int a[40][40] , sum = 10000000,visit[35] , t ,b[10];
void dfs(int i ,int tsum, int step)
{
	//printf("%d** %d\n",i,visit[1]);
    if(step == t)
	{   
	     if(tsum < sum )
			 sum = tsum;
		 return;
	}
	if(tsum > sum)
		return;
	for(int j = 0 ;j < t; j ++)
	{   
	  if(!visit[b[j]])
	  {   
		  visit[b[j]] = 1;
		  tsum = tsum + a[i][b[j]];
		  step = step +1;
		  dfs(b[j],tsum,step);
	      tsum = tsum - a[i][b[j]];
		  step = step -1;
		  visit[b[j]] = 0;
	  }
	}
	
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n; 
   while(scanf("%d",&n),n)
   {   memset(a,0,sizeof(a));
        sum = 10000000 ;
		memset(b,0,sizeof(b));
	   for(int i = 0 ;i < n ;i ++)
	    for(int j = 0 ; j < n ;j++ )
          scanf("%d",&a[i][j]);
	   int m ;
	   t = 0 ;
	   scanf("%d",&m);
	   for(int i =  0 ;i < m ; i ++)
	   {
		   int temp ,j;
		   scanf("%d",&temp);
	       for(j = 0 ;j < t; j ++)
			   if(temp == b[j])
				   break;;
		   if(j == t)
		   {
		   b[t] = temp ;
		   t = t+1;
		   }
	   }
	   for(int i =0 ;i < t;  i ++)
	   {
		   memset(visit,0,sizeof(visit));
	       visit[b[i]] = 1;
		   dfs(b[i],a[0][b[i]],1);
	   }
	   printf("%d\n",sum);

   }
return 0 ;
}
