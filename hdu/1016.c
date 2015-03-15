// File Name: 1016.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 23时01分10秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int vis[40];
int A[40];
int isp[50],n;
int tot ;
void dfs(int cur)
{
  if(cur == n && !isp[A[0] + A[n-1]])
  {
     for(int i = 0;i < n;i ++) printf(i ==0 ?"%d":" %d",A[i]);
	 printf("\n");
  }
  else for(int i = 2; i <= n;i ++)
  {
    if(!vis[i] && !isp[i+A[cur-1]])
     {
	   vis[i]  = 1;
	   A[cur] = i ; 
	   dfs(cur + 1);
	   vis[i] = 0 ;
	 }

  }
}
void init()
{
   int p = sqrt(40);
   for(int i = 2; i <= p;i++ )
   {
	
     int k = i*i;
	 while(k <= 40 )
	 {
	     isp[k] = 1;
		 k += i ;
	 }
   }

}
int main(){
  init();
  int t = 0 ; 
  while(scanf("%d",&n) != EOF)
  {
	 t++;
	 if(n % 2 == 1 )

     tot = 0 ; 
	 A[0] = 1;
	 printf("Case %d:\n",t);
	 dfs(1);
	 printf("\n");
  }

return 0 ;
}
