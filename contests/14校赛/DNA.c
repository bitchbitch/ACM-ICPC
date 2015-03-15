// File Name: DNA.c
// Author: darkdream
// Created Time: 2014年05月06日 星期二 01时05分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char str[1000000];

int ok ; 
int anst;
int anssum;
int n; 
void dostr(int len)
{

   if(len == n)
   {
      return ; 
   }
   anst ++;
   int k = len /2;
   for(int i = 1 ;i <= k ;i ++)
   {
      if(str[i] != str[len - i + 1])
		  anssum ++ ; 
   }
   dostr(len/2);
}
int main(){
     
	 clock_t en,be;
//	 be = clock();
	 freopen("DNA.in","r",stdin);
     freopen("DNA.out","w",stdout);
	 int t ;
	 scanf("%d",&t);
	 for(int i = 1;i <= t;i ++)
	 {
		anssum =  0 ; 
		anst = 0 ; 
	    scanf("%d",&n);
			scanf("%s",&str[1]);
		dostr(strlen(&str[1]));
		printf("%d %d\n",anst,anssum);
	 }
     en = clock();
//	 printf("%lf",(en -be)*1.0/CLOCKS_PER_SEC);
return 0 ;
}
