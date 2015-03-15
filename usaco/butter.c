// File Name: butter.c
// Author: darkdream
// Created Time: 2014年03月18日 星期二 18时28分52秒
/*
ID: dream.y1
PROG: butter
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

int a[1000];
int dis[810][810];
int main(){

   freopen("butter.in","r",stdin);
   freopen("butter.out","w",stdout);
   int n , p , c; 
   scanf("%d %d %d",&n,&p,&c);
   for(int i = 1;i <= n;i ++)
   {
	  scanf("%d",&a[i]);
   }
   for(int i = 1;i <= p;i ++)
	   for(int j = 1;j <= p;j ++)
	   {
         if(i ==  j)
			 dis[i][j] = 0 ; 
		 else 
	      dis[i][j] = 10000000 ;
	   }	   
   for(int i = 1;i <= c;i ++ )
   {
     int ta,tb,tc;
	 scanf("%d %d %d",&ta,&tb,&tc);
     dis[ta][tb] = tc ; 
	 dis[tb][ta] = tc; 
   }
   for(int k = 1;k <= p;k ++ )
    for(int i = 1;i <= p;i ++)
	   for(int j = 1; j <= p ;j ++)
       {
        if(dis[i][j] > dis[i][k] + dis[k][j] )
			dis[i][j] = dis[i][k] + dis[k][j];
       }
   int min = INT_MAX;
   int sum = 0 ; 
   for(int i = 1;i <= p;i ++)
   {
	 sum = 0 ; 
     for(int j = 1 ;j <= n;j ++)
		 sum  += dis[i][a[j]];
	 if(sum < min)
		 min = sum ;
   }
   
   
   printf("%d\n",min);
   
return 0 ;
}
