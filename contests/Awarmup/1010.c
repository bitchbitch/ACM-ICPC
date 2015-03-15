// File Name: 1010.c
// Author: darkdream
// Created Time: 2013年09月08日 星期日 13时15分19秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int gcd(int a, int b)
{
   return b == 0 ?a :gcd(b,a%b);
}
int a[] = {3,5,7,11,13,17,19,23};
int main(){
   int n; 
   //scanf("%d",&n);
   int temp ;
   for(int temp = 6;temp <= 50 ; temp += 2)
   {
	//  scanf("%d",&temp);
	  for(int  i= 0 ;i <= 7; i ++)
	  {
	    if(gcd(a[i],temp) == 1)
		{
		  printf("%d %d\n",temp+a[i],a[i]);
		  break;
		}
	  }
   
   }

return 0 ;
}
