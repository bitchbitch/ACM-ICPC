// File Name: d.c
// Author: darkdream
// Created Time: 2013年07月18日 星期四 20时43分56秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char str[505][505];
int  step[1000005][4];
int  visit[505][505];
struct node
{
	int x,y;
}list[260000];
int xdd[] = {0,0,1,-1};
int ydd[] = {1,-1,0,0};
int k = 0 ;
void doright(int i , int j )
{
   int up = 1; 
   int high = 1; 
   list[1].x = i ;
   list[1].y = j;
   visit[i][j] = 1;
   while(up <= high)
   {
      for(int t = 0 ;t <= 3 ;t ++)
	  {
		  int ti = list[up].x + xdd[t];
		  int tj = list[up].y + ydd[t];
		  if(str[ti][tj] == '.' && visit[ti][tj] == 0 )
		  {
                visit[ti][tj] = 1;
				high ++;
				list[high].x = ti ;
				list[high].y = tj ;
		  }
	  
	  }
	  up++;
   }
   for(int t = high ;t > 1; t --)
   {
	  str[list[t].x][list[t].y] = '#';
      k++;
	  step[k][1] = 2 ;
	  step[k][2] = list[t].x;
	  step[k][3] = list[t].y;
      k++;
	  step[k][1] = 3 ;
	  step[k][2] = list[t].x;
	  step[k][3] = list[t].y;
   }
  
}

int main(){
   memset(visit,0,sizeof(visit));
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ,m ;
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= n;i ++)
   {
      scanf("%s",&str[i][1]);
   }
 
   for(int i= 1;i <= n;i ++)
	   for(int j = 1; j <= m;j ++)
	   {
	     if(str[i][j] == '.')
		 {
		   k++;
		   step[k][1] = 1;
		   step[k][2] = i;
		   step[k][3] = j;

		 }
	   }
   for(int i = 1 ;i <= n;i ++)
	   for(int j= 1;j <= m;j ++)
	   {
		if(str[i][j] == '.')
	     doright(i,j); 
		 }
   printf("%d\n",k);
   
   for(int i =1 ;i <= k ;i ++)
   {
     if(step[i][1] == 1)
		 printf("B ");
	 else if(step[i][1] == 2)
		 printf("D ");
	 else printf("R ");
	 printf("%d %d\n",step[i][2],step[i][3]);
   }
   //for(int i = 1;i <= n;i ++)
	 // puts(&str[i][1]);
return 0 ;
}
