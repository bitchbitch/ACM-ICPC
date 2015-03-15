// File Name: dfs4.c
// Author: darkdream
// Created Time: 2013年03月14日 星期四 17时21分53秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[1000][100];
int ans = 0, i = 0  ;
int visit[1005];
void dfs(int k)
{
   if(a[k][strlen(a[k])-1] == 'm')
   {
     ans = 1;
	 return ;
   }
   if(ans)
	   return ;
   for(int  j = 0 ;j < i ; j++)
   {
       if(!visit[j] && a[j][0] == a[k][strlen(a[k]) - 1] )
	   {
	      visit[j] = 1 ;
          dfs(j);
	   }
   }

}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   char temp[100];
   memset(a,0,sizeof(a));
   while(gets(temp))
   {
      if(strlen(temp) == 1 && temp[0] == '0')
	  {
        memset(visit,0,sizeof(visit));
        for(int j = 0 ;j < i ;j ++)
		{
		    if(a[j][0] == 'b')
			 {  
				 visit[j] = 1 ; 
				 dfs(j);
			 }
		}
	  if(ans)
		  printf("Yes.\n");
	  else
		  printf("No.\n");
	  i = 0 ;
      ans = 0 ;
	  memset(a,0,sizeof(a));
	  }
	  else
	  {
		 memcpy(a[i],temp,sizeof(temp));
		 i++;
	  }
   }
return 0 ;
}
