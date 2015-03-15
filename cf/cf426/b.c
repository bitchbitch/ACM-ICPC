// File Name: b.c
// Author: darkdream
// Created Time: 2014年04月27日 星期日 23时38分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[200][200];
int m ; 
void hehe(int n)
{
   if(n % 2 == 1 )
   {
     printf("%d\n",n);
     return ; 
   }
   int ok =1; 
   for(int i =1 ;i <= n/2;i ++)
	   for(int j = 1 ;j <= m;j ++)
      {
        if(map[i][j] != map[n-i+1][j])
			ok = 0 ; 
      }
   if(ok == 0 )
	{
	   printf("%d\n",n);
	   return ;
	}else hehe(n/2);
}
int main(){
   int n ; 
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= n;i ++)
	   for(int j = 1;j <= m;j ++)
		   scanf("%d",&map[i][j]);
   hehe(n);
return 0 ;
}
