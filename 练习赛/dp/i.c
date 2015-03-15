// File Name: i.c
// Author: darkdream
// Created Time: 2013年04月10日 星期三 14时01分00秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int f[40005];
struct blocks
{
  int c,w,m;
  
};
struct blocks block
int main(){

  // freopen("/home/plac/problem/input.txt","r",stdin);
  // freopen("/home/plac/problem/output.txt","w",stdout);
  int n , v = INT_MIN ;
  scanf("%d",&n);
  for(int i = 1;i <= n; i ++ )
  {
      scanf("%d %d %d",&c[i],&w[i],&m[i]);
	  if(w[i] > v)
	  {
	   v = w[i];
	  }
  }
  memset(f,0,sizeof(f));
  for(int i = 1;i <= n; i ++)
  {
     for(int j = 1; j <= m[i] ; j++ )
	 { 
	   for(int t = w[i]; t >= c[i] ; t--)
	   {
	     f[t] = f[t]>(f[t-c[i]]+c[i])?f[t]:(f[t-c[i]]+c[i]);
	   } 
     }
  }

  printf("%d\n",f[v]);

return 0 ;
}
