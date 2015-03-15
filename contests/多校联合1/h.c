// File Name: h.c
// Author: darkdream
// Created Time: 2013年03月16日 星期六 13时07分04秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[100][100];
int visit[100][100];
int ans , t;
int x2,y2;

int xadd[] = {1,-1,0,0};
int yadd[] = {0,0,1,-1};
struct node
{
  int x , y ; 
  int step;
};
struct node list[100];
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int n , m ;
	while(scanf("%d %d %d",&n,&m,&t) != EOF)
	{
		getchar();
	memset(map,0,sizeof(map));
	memset(visit,0,sizeof(visit));
	ans = 0; 
	int x , y; 
	if(n == 0 && m == 0  && t == 0)
		  break;
	  for(int i = 1 ;i <= n ;i ++)
	  {
	    char a[100];
		gets(a);
		for(int j = 0 ; j < strlen(a) ; j ++)
		{
		  if(a[j] == 'S')
		  {
		    x = i; 
			y = j+1;
			visit[x][y] = 1;
		  }
		  if(a[j] == 'D')
		  {
		    x2 = i;
			y2 = j+1;
			map[x2][y2] = 1; 

		  }
		  if(a[j] == '.')
		  {
		    map[i][j+1] = 1;
		  }

		}
	  }
	  /*for(int i = 1 ;i <= n; i++)
	  {  for(int j = 1; j <= m ; j ++)
			  printf("%d",map[i][j]);
	   printf("\n");
	  }*/
	  list[0].x = x;
	  list[0].y = y;
	  list[0].step = 0 ;
	  int rear = 0 , last = 0 ,hehe = 0;
	  while(rear <= last)
	  {
	     if(list[rear].x  == x2 && list[rear].y == y2 &&  list[rear].step  <= t)
		 {
		   ans = 1 ;
		   break;
		 }
		 for(int i = 0 ;i < 4; i ++)
		 {
		   int xx = list[rear].x + xadd[i];
		   int yy = list[rear].y + yadd[i];
		   if(map[xx][yy] && visit[xx][yy] == 0)
		   { //printf("%d %d\n",xx,yy);
			  visit[xx][yy] = 1;
		      if(rear == 0)
				  hehe ++;
			  last ++;
			  list[last].x = xx;
			  list[last].y = yy;
              list[last].step = list[rear].step +1;

		   }
		 }
		 rear++;
	  }
	 // printf("%d\n",list[rear].step);
	  if(ans == 1 && (t - list[rear].step) % 2 == 0)
       { 
		   printf("YES\n");
	    
	   }
	  else
		  printf("NO\n");

	}

return 0 ;
}
