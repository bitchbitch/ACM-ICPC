// File Name: b.c
// Author: darkdream
// Created Time: 2014年01月18日 星期六 00时46分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
__int64 a,b,w,x,c;
__int64 hs[2000];
int main(){
   scanf("%I64d %I64d %I64d %I64d %I64d",&a,&b,&w,&x,&c);
   if(c <= a)
   {
     printf("0\n");
	 return 0 ; 
   }
   memset(hs,0,sizeof(hs));
   __int64 k = 0; 
   __int64 t = 0 ; 
   __int64 st = 0 ; 
   while(!hs[b])
   {
	   hs[b] = 1; 
       if(b >= x)
	     {
		   b = b - x; 
		 }
		else {
		   b = w - (x - b);
		   t++;
		}
		k++;
   }
  // printf("%I64d\n",k);
   
   __int64 n = (c-a)/(k-t);
   n = n - 2;
   st = n*k;
   a = a - n*t;
   c = c - k*n;
   while(c > a)
   {
	   c--;
       if(b >= x)
	     {
		   b = b - x; 
		 }
		else {
		   b = w - (x - b);
		   a --;
		}
		st++;
   }
   printf("%I64d\n",st);
return 0 ;
}

