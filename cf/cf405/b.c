// File Name: b.c
// Author: darkdream
// Created Time: 2014年03月22日 星期六 23时36分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int n ; 
char str[4000];
int  a[4000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   scanf("%d",&n);
   scanf("%s",str);
   memset(a,0,sizeof(a));
   for(int i = n-1;i >= 0;i --)
   {
      if(str[i] == 'L')
	  {
		 int x = i;
		 int t = 1 ; 
	     while(str[x] != 'R' && x >= 0 )
		 {
		     a[x] = -t;
			 t ++ ; 
			 x -- ; 
		 }
		 i = x; 
	  }
   }
   for(int i = 0;i < n;i ++)
   {
      if(str[i] == 'R')
	  {
		 int x = i; 
		 int t = 1;
	     while(str[x] != 'L' && x < n)
		 {
		     a[x] += t ;
			 t++;
			 x ++ ; 
		 }
		 i = x; 
	  }
   }
   int sum = 0 ; 
   for(int i  = 0 ;i < n;i ++)
	   if(a[i] == 0 )
		   sum ++ ; 
   printf("%d\n",sum);
return 0 ;
}
