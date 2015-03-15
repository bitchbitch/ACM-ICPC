// File Name: e.c
// Author: darkdream
// Created Time: 2014年03月05日 星期三 20时27分33秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[4000];
int hs[11000];
int main(){

  int n ,m;
  while(scanf("%d %d",&n,&m)!= EOF)
  {
	memset(hs,0,sizeof(hs));
  for(int i = 1;i <= n;i ++)
	  scanf("%d",&a[i]);
   for(int i= 1; i <= n;i ++)
	   for(int j = i+1;j <= n;j ++)
	   {
	     hs[a[i] +a[j]] ++  ;
	   }
   int t = 0 ; 
   for(int i = 10000;i >= 0 ;i -- )
   {
      while(hs[i])
	  {
	    printf(t == 0 ?"%d":" %d",i);
		t ++;
		hs[i]--;
		if(t == m )
			break;
	  }
	  if(t == m )
		  break;
   }
  printf("\n");
  }
return 0 ;
}
