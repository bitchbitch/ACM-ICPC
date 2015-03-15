// File Name: uva10004.c
// Author: darkdream
// Created Time: 2013年06月02日 星期日 17时14分04秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int n,ok;
int num[205];
int map[205][205];
int visit[205];
void dfs(int k,int sum,int color)
{
  printf("%d\n",k);
  if(sum == n)
  {
    ok = 1; 
	return ;
  }
  for(int i = 0 ;i < num[k];i++ )
  {
       if(visit[map[k][i]])
	   {
	     if(visit[map[k][i]] == visit[k])
			 return;
	   }
  }
  int p = 0 ;
  for(int i = 0 ;i < num[k];i++)
  {
	  if(i == k )
		  continue;
      if(!visit[i])
	  {
	    for(int j = 1; j <= 4; j ++)
		{
		  if(j == color)
			  continue;
		  visit[i] = j;
		  dfs(i,sum+1,j);
		}
	  }
  }

}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   while(scanf("%d",&n) != EOF)
   {
     if(n == 0 )
		 break;
	 int l;
	 ok = 0 ;
	 scanf("%d",&l);
	 memset(num,0,sizeof(num));
	 memset(map,0,sizeof(map));
	 memset(visit,0,sizeof(visit));
	 int tempa,tempb;
	 for(int i = 1; i<= l; i ++ )
	 {
	     scanf("%d %d",&tempa ,&tempb);
		 map[tempa][num[tempa]] = tempb;
		 num[tempa]++;
         map[tempb][num[tempb]] = tempa;
		 num[tempb]++;
	 }
	 visit[0] = 1;
	 dfs(0,1,1);
     if(ok)
		 printf("BICOLORABLE.\n");
	 else 
		 printf("NOT BICOLORABLE.\n");
   }
return 0 ;
}
