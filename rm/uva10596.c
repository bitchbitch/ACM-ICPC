// File Name: uva10596.c
// Author: darkdream
// Created Time: 2013年06月15日 星期六 20时44分39秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[204][204];
int kk[204];
int visit[204];
int n , ok ;
void dfs(int k )
{
   for(int i =  0 ;i < n;i ++)
   {
     if(map[k][i] != 0  && visit[i] == 0)
	    {	 
	       visit[i] = 1;
		   dfs(i);
		}
   }

}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int  m ;
   while(scanf("%d %d",&n,&m) != EOF)
   { int a,  b;
	 int begin = 0;
	 ok = 1;
	 memset(map,0,sizeof(map));
     memset(visit,0,sizeof(visit));
	 memset(kk,0,sizeof(kk));
	 while(m--)
	 {
	   scanf("%d %d",&a,&b);
	   map[a][b]++ ;
	   map[b][a]++;
	   kk[a] ++;
	   kk[b] ++;
	   begin = b;
	 }
	 visit[b] = 1;
	 dfs(b);
	 for(int i = 0 ; i < n;i ++)
	 {
	   if( visit[i] == 0  )
		   ok = 0 ;
	 }
	 for(int i =0 ;i < n;i ++ )
	 {
	   if(kk[i] %2 == 1)
		   ok = 0;
	 }
	 if( ok == 1)
		 printf("Possible\n");
	 else
		 printf("Not Possible\n");
   }
   
return 0 ;
}
