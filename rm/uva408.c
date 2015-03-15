// File Name: uva408.c
// Author: darkdream
// Created Time: 2013年03月02日 星期六 19时45分02秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int gcd(int a , int b)
{
 return (b==0)?a:gcd(b,a%b);
}
int main(){

  // freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int n , m , t = 0;
  while(scanf("%d %d",&n,&m)!=EOF)
  {
	  printf("%10d%10d    ",n,m);
     if(gcd(n,m) == 1 && m != n)
		 printf("Good Choice\n\n");
	 else
		 printf("Bad Choice\n\n");
	t++;
  }
return 0 ;
}
