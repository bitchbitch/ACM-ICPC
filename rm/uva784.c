// File Name: uva784.c
// Author: darkdream
// Created Time: 2013年05月22日 星期三 21时15分59秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[100][100];
int visit[100][100];
struct node
{
  int x, y ;
}nodes[1000];
int xadd[] = {+1,-1,0,0};
int yadd[] = {0,0,+1,-1};
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ;
   scanf("%d",&n);
   getchar();
   while(n--)
   {
	   memset(str,0,sizeof(str));
	   memset(visit,0,sizeof(visit));
	   int m ;
       for(int i =1 ; ;i ++)
	   {
	      gets(&str[i][1]);
		  if(str[i][1] == '_')
		  {
		    m = i-1;
			break;
		  }
	   }
	   int fx,fy;
	   for(int i = 1; i <= m;i ++)
	   {
	      for(int j = 1; j <= 80 ;j ++)
		  {
		    if(str[i][j] == '*')
			{  
			    fx = i ;
				fy = j;
				break;
			}
		  }
	   }
	   int low = 1, high = 1;
	   nodes[1].x = fx;
	   nodes[1].y = fy;
	   str[fx][fy] = '#';
	   while(low <= high)
	   {
		  for(int tp = 0 ; tp < 4; tp++)
		  {
		     int tx = nodes[low].x + xadd[tp];
			 int ty = nodes[low].y + yadd[tp];
			 if(str[tx][ty] == ' ')
			 {
			     str[tx][ty] = '#';
				 high++;
				 nodes[high].x = tx;
				 nodes[high].y = ty;
			 }
			 
		  }
		  low++;
	     
	   }
	   for(int i =1 ;i <= m+1;i ++)
	   {
	      puts(&str[i][1]);
	   }


   }
return 0 ;
}
