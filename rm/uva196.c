// File Name: uva196.c
// Author: darkdream
// Created Time: 2013年06月16日 星期日 20时29分05秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

struct node
{
  int num;
  int isnum;
  char str[100];
};
struct node map[1000][1000];
int n , m;
int dfs(int x,int y)
{
 // printf("%d %d\n",x,y);
  if(map[x][y].isnum == 1)
  {
	//printf("%d**%d\n",x,y);
     return map[x][y].num;
	
  }
  int sum = 0 ;
  int tx = 0;
  int ty = 0;
  int len = strlen(map[x][y].str);
  char *p = map[x][y].str;
  for(int i = 1;i <= len; i ++)
  {
     if(i == len || p[i] == '+')
	 {
		 sum += dfs(ty,tx);
		 tx = 0 ;
		 ty = 0 ;
		 continue;
	 }
    if(isalpha(p[i]))
	{
	  tx = tx*26 +(p[i] - 'A' + 1);
	}
	else if(isdigit(p[i]))
    {
		
		ty = ty*10 + (p[i] -'0' );
	}
  }
  map[x][y].num = sum; 
  map[x][y].isnum = 1;
  return sum;
  
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(map,0,sizeof(map));
	    scanf("%d %d",&m,&n);
		for(int i = 1; i <= n;i ++)
		{
		  for(int j = 1;j <= m ;j ++)
		  {  scanf("%s",map[i][j].str);
		    
			  if(map[i][j].str[0] != '=')
			  {
			     sscanf(map[i][j].str,"%d",&map[i][j].num);
				 map[i][j].isnum = 1;
			  }
			
		  }
		}
	   for(int i = 1; i <= n;i ++)
		   for(int j = 1; j <= m;j ++)
		   {
		       if(map[i][j].isnum == 0)
			     {
				   dfs(i,j);
				 } 
		   }
	   for(int i =1;i <= n;i ++)
	   {
	      for(int j =1 ;j <= m; j ++)
		  {
		     if(j != 1)
				 printf(" ");
				 printf("%d",map[i][j].num);
		  }
		  printf("\n");
	   }
	}
return 0 ;
}
