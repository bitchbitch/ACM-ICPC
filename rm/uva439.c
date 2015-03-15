// File Name: uva439.c
// Author: darkdream
// Created Time: 2013年05月25日 星期六 14时24分17秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node 
{
   int x,y,step;
};

struct node list[10000];
int xadd[] = {1,1,-1,-1,2,2,-2,-2};
int yadd[] = {2,-2,2,-2,1,-1,1,-1};
int is(int x)
{
  if( x >= 1 && x <= 8 )
	  return 1;
   return 0 ;
}
int visit[10][10];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int a, b;
   char ca,cb;
   while(scanf("%c%d %c%d",&ca,&a,&cb,&b) != EOF)
   {
	getchar();
	 memset(list,0,sizeof(list));
	 memset(visit,0,sizeof(visit));
     int dx = cb -'a' +1;
	 int dy = b ;
     list[1].x = ca - 'a' +1;
	 list[1].y = a;
	 list[1].step = 0;
	 visit[list[1].x][list[1].y] = 1;
	 int low = 1 , high = 1;
	 while(low <= high)
	 {
		 if(list[low].x == dx && list[low].y == dy)
		 {
		    break;
		 }
	    for(int i = 0 ; i <= 7 ;i ++)
		{
		  int tx = list[low].x + xadd[i];
		  int ty = list[low].y + yadd[i];
		  if(!visit[tx][ty] && is(tx)&&is(ty))
		  {
			  visit[tx][ty] = 1;
		      high ++;
			  list[high].x = tx;
			  list[high].y = ty;
			  list[high].step = list[low].step+1;
		  
		  }
		}
		low++;
	 }
	 printf("To get from %c%d to %c%d takes %d knight moves.\n",ca,a,cb,b,list[low].step);
   }
return 0 ;
}
