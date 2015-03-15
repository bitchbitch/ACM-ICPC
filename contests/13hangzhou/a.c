// File Name: a.c
// Author: darkdream
// Created Time: 2014年05月06日 星期二 18时52分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int n , m;
struct node{
  int x, y ,step;
}list[10005];
int visit[104][104];
int map[104][104];
struct node1{
  int x, y ; 
}a[10];
int main(){


	  while(scanf("%d %d",&n,&m) != EOF)
	  {
		memset(map,0,sizeof(map));
	    memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i ++)
		{
		  char str[104];
		  scanf("%s",&str[1]);
		  for(int j = 1;j <= m;j ++)
		  {
		     if(str[j] == '#')
			 map[i][j] = 1;
			 else if(str[j] == '@')
			 {
			    a[0].x = i ; 
				a[0].y = j; 
			 }	 
		  }
		}
		int  k ; 
		scanf("%d",&k);
		for(int i = 1;i <= k;i ++)
		    scanf("%d %d",&a[i].x,&a[i].y);
		f
		
        
		
	  }
	  
return 0 ;
}
