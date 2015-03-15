// File Name: a.c
// Author: darkdream
// Created Time: 2013年04月09日 星期二 20时09分15秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int f[10005];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n , v;

	  int c[505],w[505];
	  scanf("%d %d",&n,&v);
	  v = v - n ;
	  scanf("%d",&n);
	  memset(f,0,sizeof(0));
      f[0] = 0;
      for(int i = 1; i <= 10000; i ++)
		  f[i] = INT_MIN;
	  for(int i = 1;i <= n;i ++)
		  scanf("%d %d",&w[i],&c[i]);
	  for(int i = 1; i <= n; i ++)
        {
			/*for(int j = 0 ; j <= v ;j ++)
				printf("%d ",f[j]);
			printf("\n");*/
			for(int j = c[i] ;j <= v; j++)
			{
			  if(f[j] > 0 && f[j-c[i]]+w[i] > 0)
               {
			        f[j] =  f[j] > (f[j-c[i]]+w[i])?(f[j-c[i]]+w[i]) :f[j];
			   }
			  else if(f[j] < 0 && f[j-c[i]]+w[i] >= 0)
			   {
			        f[j] = f[j-c[i]]+w[i];
			   }
			  else if(f[j] >= 0 && f[j-c[i]]+w[i] < 0)
			   {
			         f[j] = f[j];
			   }
              else if(f[j] == 0 && f[j-c[i]] + w[i] < 0)
				  f[j] = 0 ;
			  else  f[j] = INT_MIN;
			}
		}
	 /* for(int i = 1; i <= n;i ++)
	  {
	    for(int j = 1 ; j <= v; j ++)
			printf("%d ",f[i][j]);
		printf("\n");
	  }*/
	  if(f[v] >= 0 )
	  printf("The minimum amount of money in the piggy-bank is %d.\n",f[v]);
	  else
		  printf("This is impossible.\n");

   }
return 0 ;
}
