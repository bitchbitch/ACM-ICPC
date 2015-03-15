// File Name: uva705.c
// Author: darkdream
// Created Time: 2013年05月24日 星期五 18时58分27秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[1000][1000];
char str[100][100];
int sum,max;
int xadd[] = {0,0,1,-1};
int yadd[] = {1,-1,0,0};

void change(int i , int j , char c)
{
   for(int t = 3*i -2; t <= 3*i ;t++)
	   for(int p = 3*j-2 ; p <= 3*j ; p++)
	   {
	     map[t][p] = 1;
	   }
   if(c == '/')
   {
	   map[3*i-2][3*j] = 0;
	   map[3*i-1][3*j-1] = 0;
	   map[3*i][3*j-2] =0 ;
    
   }
   else 
   {
      map[3*i-2][3*j-2] = 0;
	  map[3*i-1][3*j-1] = 0;
	  map[3*i][3*j] = 0 ;
   }
}
int FloodFill(int i , int j)
{
   if(!map[i][j])
	   return 0 ;
   map[i][j] = 0 ;
   int sum = 1;
   for(int t = 0 ;t < 4; t ++)
   {
     sum +=  FloodFill(i+xadd[t],j+yadd[t]);
   }
  return sum;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int n , m ,CASE = 0;
	while(scanf("%d %d",&m,&n) != EOF,n,m)
	{
	   CASE ++;
	   memset(map,0,sizeof(map));
	   memset(str,0,sizeof(str)); 
	   sum = 0;
	   max = 0;
	  for(int i = 1; i <= n;i ++)
	  {
	      scanf("%s",&str[i][1]);
		  for(int j = 1; j <= m; j ++)
           change(i,j,str[i][j]);
	  }
	  for(int i = 1;i <= 3*n; i ++)
	  { 
		  FloodFill(i,1);
		  FloodFill(i,3*m);
	  }
	  for(int i = 1;i <= 3*m; i ++)
	  { 
		  FloodFill(1,i);
		  FloodFill(3*n,i);
	  }
	  for(int i = 1;i <= 3*n ;i ++)
		  for(int j = 1;j <= 3*m ;j ++)
		  {
		    int temp = FloodFill(i,j)/3;
			if(temp >max)
				max = temp;
			if(temp)
				sum++;
		  }
	 printf("Maze #%d:\n",CASE);
	 if(sum)
       printf("%d Cycles; the longest has length %d.\n\n",sum,max);
	 else
		 printf("There are no cycles.\n\n");
	}
return 0 ;
}
