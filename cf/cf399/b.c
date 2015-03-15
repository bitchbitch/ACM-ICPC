// File Name: b.c
// Author: darkdream
// Created Time: 2014年03月02日 星期日 00时05分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[1000];
__int64  p(int x, int n)
{
     __int64 ans = 1; 
	 for(int i = 1;i <= n;i ++)
		 ans *= x; 
	 return ans ; 
}
int main(){
   int n ;
   scanf("%d",&n);
   scanf("%s",str);
   __int64 ans = 0 ; 
   int len = strlen(str);
   for(int i = 0; i < len ;i++)
   {
        if(str[i] == 'B')
		{
		  ans += p(2,i);
		}
   }
   printf("%I64d\n",ans);
   
 return 0 ;
}
