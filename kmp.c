// File Name: kmp.c
// Author: darkdream
// Created Time: 2013年06月17日 星期一 12时02分21秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   char str[100];
   char str1[10000];
   int next[100];
   scanf("%s",&str[1]);
   scanf("%s",&str1[1]);
   int k = 0 ;
   int m = strlen(&str[1]);
   int n = strlen(&str1[1]);
   for(int q = 2 ; q <= m; q++)
   {
       while (k > 0 && str[k+1] != str[q])
	   {  
		  k = next[k];
	   }
	   if( str[k+1] == str[q])
	       k = k +1;
	   next[q] = k ;

   }
   //for(int i = 1;i <= m ;i ++)
     //printf("%d ",next[i]);
   int  q = 0 ;
   for(int i = 1; i <= n;i ++)
    {
       while( q > 0  && str[q+1] != str1[i])
	        q  = next[q];
	   if(str[q+1] == str1[i])
	      q = q+ 1;
	   if(q == m)
	   {  printf("Pattern occurs with shift %d\n",i-m);
	     q = next[q];
	   }
    }

return 0 ;
}
