// File Name: uva532.c
// Author: darkdream
// Created Time: 2013年05月25日 星期六 14时49分16秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[40][40][40];
int  visit[40][40][40];
int xadd[] = {1,-1,0,0};
int yadd[] = {0,0,-1,1};
struct node
{
  int z, x, y,step;
};
struct node list[1000000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int l , r, c;
   while(scanf("%d %d %d",&l,&r,&c) != EOF,l)
   {
	
	  getchar();
	  memset(list,0,sizeof(list));
	  memset(visit,0,sizeof(visit));
	  memset(str,0,sizeof(str));
	  int dz,dx,dy,ok = 0 ;
      for(int i = 1;i <= l ; i ++ )
	   for(int j = 1;j <= r; j ++)
	   {  scanf("%s",&str[i][j][1]);
	      if(strchr(&str[i][j][1],'S'))
		  {
		    list[1].z = i ;
			list[1].x = j ;
			list[1].y = strchr(&str[i][j][1],'S') - &str[i][j][1]+1;
            list[1].step = 0 ;
			visit[list[1].z][list[1].x][list[1].y] = 1;
		  }
		  if(strchr(&str[i][j][1],'E'))
	      {
		    dz = i ;
			dx = j ;
			dy = strchr(&str[i][j][1],'E') - &str[i][j][1]+1;
			str[dz][dx][dy] = '.';
		  }
	   
	   }
	  int low =  1, high = 1;
	  while(low <= high)
	  {
		 //printf("%d %d %d\n",list[low].z,list[low].x,list[low].y);
	     if(list[low].z == dz && list[low].x == dx && list[low].y == dy)
		 {
		   ok = 1;
		   break;
		 }
		 for(int i = 0 ;i < 4 ; i++)
		 {
		   int tz = list[low].z;
		   int tx = list[low].x + xadd[i];
		   int ty = list[low].y + yadd[i];
		   if(str[tz][tx][ty] == '.' && !visit[tz][tx][ty])
		   {
		      visit[tz][tx][ty] = 1;
			  high ++;
			  list[high].z = tz;
			  list[high].x = tx;
			  list[high].y = ty;
			  list[high].step = list[low].step+1;
		   }

		 }
		 int tz = list[low].z;
		 int tx = list[low].x;
		 int ty = list[low].y;
		   if(str[tz+1][tx][ty] == '.' && !visit[tz+1][tx][ty])
		   {
		      visit[tz+1][tx][ty] = 1;
			  high ++;
			  list[high].z = tz+1;
			  list[high].x = tx;
			  list[high].y = ty;
			  list[high].step = list[low].step+1;
		   }
		   if(str[tz-1][tx][ty] == '.' && !visit[tz-1][tx][ty])
		   {
		      visit[tz-1][tx][ty] = 1;
			  high ++;
			  list[high].z = tz-1;
			  list[high].x = tx;
			  list[high].y = ty;
			  list[high].step = list[low].step+1;
		   }
		low++;

	  }
	  //printf("%d\n",low);
	  if(ok == 0)
		  printf("Trapped!\n");
	  else
		  printf("Escaped in %d minute(s).\n",list[low].step);
   }
return 0 ;
}
