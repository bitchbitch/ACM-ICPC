// File Name: d.c
// Author: darkdream
// Created Time: 2013年05月18日 星期六 11时23分43秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int visit[505][505];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int t ;
	scanf("%d",&t);
	while(t--)
    {
	  int a, b , sum = 0 ;
	  memset(visit,0,sizeof(visit));
	  scanf("%d %d",&a,&b);
	  int tempa[1001],tempb[1001];
	  for(int i = 1; i <= b; i++)
	  {
	      scanf("%d",&tempa[i]);
	  } 
	  for(int i = 1; i <= b; i++)
		  scanf("%d",&tempb[i]);
	  for(int i = 1; i <= b; i ++)
	  {
		  if(!visit[tempa[i]][tempb[i]])
		  {
		    visit[tempa[i]][tempb[i]] = 1;
			visit[tempb[i]][tempa[i]] =1 ;
			sum++;
		  }
	  
	  }
	 printf("%.3f\n",1.0*sum/a);
	}
return 0 ;
}
