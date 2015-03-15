// File Name: shusu.c
// Author: darkdream
// Created Time: 2014年04月09日 星期三 16时07分35秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int hs[1005];
int b[1004];
void sai()
{

   for(int i = 2;i < 1000; i ++)
   {
      if(!hs[i])
	  {
	     int k = i *i; 
		 while(k < 1000)
		 {
		    hs[k] = 1; 
			k+= i ;
		 }
	  }
   }
   for(int i = 2;i < 1000 ;i ++)
	   if(!hs[i])
		   printf("%d\n",i);

}
int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   memset(hs,0,sizeof(hs));
   sai();
   return 0 ;
}
