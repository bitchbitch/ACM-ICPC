// File Name: uva572.c
// Author: darkdream
// Created Time: 2013年05月22日 星期三 19时19分08秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[128][128];
int visit[128][128];
struct node 
{
    int i , j ;

}nodes[10000];
int xadd[] = {+1,-1,0,0,+1,+1,-1,-1};
int yadd[] = {0,0,+1,-1,+1,-1,-1,+1};
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int n ,m; 
	while(scanf("%d %d",&n,&m) != EOF)
	{
		memset(str,0,sizeof(str));
		memset(nodes,0,sizeof(nodes));
	    memset(visit,0,sizeof(visit));
		if(n == 0 && m == 0)
			break;
		for(int i = 1;i <= n; i ++)
		{
		  scanf("%s",&str[i][1]);
		}
		int sum = 0 ;
		for(int i = 1 ; i <= n ;i ++)
	    {
		   for(int j = 1 ;j <= m ; j++)
		   {
		     if(str[i][j] == '@' && visit[i][j] == 0)
			 {
			    memset(nodes,0,sizeof(nodes));
				sum++;
				nodes[1].i = i ; 
				nodes[1].j = j ;
				visit[i][j] =1 ;
                int low  = 1, high = 1;
				while(low <= high )
				{
				   for(int k = 0 ;k < 8 ;k ++)
				   {  
					  int tx = nodes[low].i + xadd[k];
					  int ty = nodes[low].j + yadd[k];
				      if(str[tx][ty] == '@' && !visit[tx][ty] )
					  {
					    high++;
						visit[tx][ty] = 1; 
						nodes[high].i = tx;
						nodes[high].j = ty;
					  }
				   }
				   low++;
				}
			 }
		   }
		}
		printf("%d\n",sum);
			   
	}
return 0 ;
}
