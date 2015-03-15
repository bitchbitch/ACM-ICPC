// File Name: comehome.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 13时24分02秒
/*
ID: dream.y1
PROG: comehome
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[100][100];
int hsa[200]  = {0};
int hs1[200] = {0};
int is[200] = {0};
int ans[1000];
int visit[100];
int main(){
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
   int t;
   scanf("%d",&t);
   for(int i = 1;i<= 99;i ++)
	   for(int j =1;j <= 99 ; j ++)
	   {
	      map[i][j] = 10000000;
	   }
   int k = 0 ;
   while(t--)
   {
     char a, b ;
	 int v;
	 getchar();
	 scanf("%c %c %d",&a,&b,&v);
	 {
	   if(!hsa[a])
	   {
		 k ++;
		   hsa[a] = k;
		   hs1[k] = a;
	     if(a <= 90)
		 {
		   is[hsa[a]] = 1;
		 }
		 
	   }
	   if(!hsa[b])
	   {
		   k ++;
		   hsa[b] = k;
		   hs1[k] = b;
	     if(b <= 90)
		 {
		   is[hsa[b]] = 1;
		 } 
	   
	   }
	   if(v <= map[hsa[a]][hsa[b]])
	   {
	   map[hsa[a]][hsa[b]] = v;
	   map[hsa[b]][hsa[a]] = v;
	   }
	 }
   }

  /* printf("%d\n",k);
   for(int i  = 1;i <= k;i ++)
   {
     for(int j= 1;j <= k;j ++)
		 printf("%d ",map[i][j]);
	 printf("\n");
   }*/
   
   for(int i = 1;i <= k;i ++)
   {
     ans[i] = 100000000;
   }
   int n = hsa['Z'];
   ans[n] = 0 ;
   memset(visit,0,sizeof(visit));
   for(int i = 1;i <= k;i ++)
   {
	  int x, m = 100000000;
      for(int j =1 ;j <= k; j ++)
		  if(!visit[j] && ans[j] <= m ) m = ans[x=j];
	  visit[x] = 1; 
	  for(int j = 1;j <= k ;j ++)
           if(  ans[j]  >ans[x] + map[x][j])
			   ans[j] = ans[x] + map[x][j];
   }

   int min = 10000000 ;
   int s = 0 ;
   for(int i = 1;i <= k ;i ++)
   {
	 //  printf("%d %d\n",ans[i],is[i]);
	   if(i == n)
		   continue;
	   if(is[i] && ans[i] < min)
	   {
	     min = ans[i];
	     s= i ; 
	   }
   
   }
   //printf("\n");
   printf("%c %d\n",hs1[s],ans[s]);
return 0 ;
}
