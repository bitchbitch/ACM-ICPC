// File Name: h.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 19时27分31秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int isprime(int n )
{
  double k = sqrt(n);
  for(int i = 2 ;i <= sqrt(n); i ++)
	  if(n %i == 0 )
		  return 0 ;
  return 1;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int n ;
	while(scanf("%d",&n) != EOF)
	{
	  int temp;
	  int sum = 0 ;
	  for(int i = 1;i <= n;i++)
	  {scanf("%d",&temp);
		  if(isprime(temp) == 1)
			  sum++;
	  }
	  printf("%d\n",sum);
	}
return 0 ;
}
