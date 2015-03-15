// File Name: a.c
// Author: darkdream
// Created Time: 2014年02月03日 星期一 23时01分24秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int n ; 
int a[200];
int hs[200];
int gcd(int a, int b)
{
  return b == 0 ? a:gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for(int i = 2; i <= n ;i ++)
	{
	  a[i] =  gcd(a[i],a[i-1]);
	}
	printf("%d\n",a[n]*n);
	return 0 ;

}
