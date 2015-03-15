// File Name: floyd.c
// Author: darkdream
// Created Time: 2014年04月02日 星期三 17时04分34秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int map[100][100];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n;  
   scanf("%d",&n);
   int m ; 
   scanf("%d",&m);
   for(int i =1;i <= n;i ++)
	   for(int j = 1; j <= n;j ++)
	   {   map[i][j] = 100;
	      if(i == j )
			  map[i][j] = 0 ; 
	   }
   for(int i = 1;i <= m;i ++)
   {
       int a, b, c; 
	   scanf("%d %d %d",&a,&b,&c);
	   map[a][b] = c; 
	   map[b][a] = c;
   }
   for(int k = 1;k <= n;k ++)
   {
	   for(int i = 1; i <= n; i ++)
		   for(int j = 1;j <= m;j ++)
		   {
		      if(map[i][j] > map[i][k] + map[k][j])
			  {  map[i][j] =  map[i][k] + map[k][j];
			     printf("i = %d j = %d k = %d \n",i,j,k);
			  }
		   }
	   for(int i = 1;i <= n;i ++)
	   { for(int j = 1; j <= n;j ++)
	      printf("%10d ", map[i][j]);
		  printf("\n");
	   }
	   printf("\n");
   }	   
return 0 ;
}
