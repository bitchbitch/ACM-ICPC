// File Name: d.c
// Author: darkdream
// Created Time: 2013年04月10日 星期三 10时04分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int f[255];
int c[6] = {0,50,25,10,5,1};
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int  v;
   while(scanf("%d",&v) != EOF)
   {
        memset(f,0,sizeof(f));
		f[0] = 1 ;
		for(int i = 1;i <= 5; i ++)
		{
	      for(int j = c[i];  j <= 100 ;j++ )
		  {  
		   f[j] = f[j] +f[j-c[i]] ;
		  }
		}
		printf("%d\n",f[v]);
   }
return 0 ;
}
