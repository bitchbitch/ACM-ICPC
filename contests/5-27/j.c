// File Name: j.c
// Author: darkdream
// Created Time: 2013年06月01日 星期六 09时24分43秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct point
{
	int x, y;
};
struct yuan
{
   int x, y;
   int k ;
   struct point points[3000];
}yuans[12];
int Visit[100][100];
int n , last,ans, ok,t; 
int  dis(int i ,int x, int y )
{
   return abs(yuans[i].x-x ) + abs(yuans[i].y-y);
}
void expend(int k ,int temp )
{
  yuans[k].k =0 ;
  for(int i = 1;i <= n;i++)
  {
    for(int j = 1; j <= n; j ++)
		if(dis(k,i,j) <= temp )
		  {
		    yuans[k].points[yuans[k].k].x = i ;
		    yuans[k].points[yuans[k].k].y = j ;
			yuans[k].k++;
		  }
  }
}
void dfs(int k , int step ,int sum)
{
  if(last == sum)
  {
     if(step < ans)
		 ans = step;
	 ok = 1;
	 return ;
  }
  if( step >= ans)
	  return;
  for(int s = k+1; s <= t; s++)
  {
    int temp =0 ;
	struct point points[3000] = {0};
	for(int i = 0 ;i < yuans[s].k ; i ++)
	{
	   if(!Visit[yuans[s].points[i].x][yuans[s].points[i].y])
	   {
	     points[temp].x = yuans[s].points[i].x;
		 points[temp].y = yuans[s].points[i].y;
		 Visit[points[temp].x][points[temp].y] = 1;
		 temp++;
	   }
	
	}
	dfs(s,step+1,sum+temp);
	for(int i = 0 ;i < temp; i++)
	  Visit[points[i].x][points[i].y] = 0;
  
  }
 return ;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  while(scanf("%d",&n) != EOF)
  {
     if(n == 0 )
		 break;
	 memset(yuans,0,sizeof(yuans));
	 memset(Visit,0,sizeof(Visit));
	 scanf("%d",&t);
	 last = n*n - t;
	 ans = t;
	 ok = 0 ;
	 for(int i = 1;i <= t;i ++)
	 {  scanf("%d %d",&yuans[i].x,&yuans[i].y);
	    Visit[yuans[i].x][yuans[i].y] = 1;
	 }
	 int temp;
     for(int i =1 ;i <= t; i ++)
	 {
	    scanf("%d",&temp);
		expend(i,temp);
	 }
	 dfs(0,0,0);
	 if(1 == ok)
	   printf("%d\n",ans);
	 else 
	   printf("-1\n");

  }
return 0 ;
}
