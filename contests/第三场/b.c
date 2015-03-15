// File Name: b.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 19时02分11秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
__int64 a[100005];
int main(){

  // freopen("/home/plac/problem/input.txt","r",stdin);
  // freopen("/home/plac/problem/output.txt","w",stdout);
  __int64  n ;
  a[0] = 0;
  for(__int64  i = 1;i <= 100000; i ++)
  {
	  if(i%3 == 0)
		  a[i] = a[i-1]+i*i*i;
	  else
		  a[i] = a[i-1]+i;

  }
  while(scanf("%I64d",&n) != EOF)
  {
    if(n  < 0)
		break;
	else
	  printf("%I64d\n",a[n]);
  }
return 0 ;
}
