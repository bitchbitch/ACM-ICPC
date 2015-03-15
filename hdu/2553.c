// File Name: 2553.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 19时38分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int tot,n;
int c[20];
int visit[4][50];
void search(int cur)
{
   
   if(cur == n)
   {   tot++;

       return;
   }
   
   for(int i = 0 ;i < n;i ++)
   {
      if(!visit[0][i] &&  !visit[1][cur+i] && !visit[2][cur-i+n]) 
	  {
		c[cur] = i ;
	    visit[0][i] = visit[1][cur+i] = visit[2][cur-i+n] = 1;
		search(cur+1);
	    visit[0][i] = visit[1][cur+i] = visit[2][cur-i+n] = 0; 
	  }
   }
}
int ans[20] = {0};
int main(){
  for(n = 1;n <= 10;n ++)
  {
	  memset(visit,0,sizeof(visit));
      tot = 0 ; 
	  search(0);
	  ans[n] = tot;
  }
  while(scanf("%d",&n) != EOF)
  {
	if(n == 0 )
		break;
	printf("%d\n",ans[n]);
  }

return 0 ;
}
