// File Name: stars.c
// Author: darkdream
// Created Time: 2013年03月27日 星期三 16时52分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[32005];
int SUM[15005];
int n ;
int lowbit(int x)
{
  return x&(-x);
}
int sum(int x)
{
    int res = 0;
	while(x>=1)
	{
	   res += a[x];
       x -= lowbit(x);
	}
	return res;
}
void update(int x)
{
    while( x <= 32001)
	{
	  a[x] ++;
	  x += lowbit(x);
	}
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
  // freopen("/home/plac/problem/output.txt","w",stdout);
  scanf("%d",&n); 
  
    memset(a,0,sizeof(a) );
	memset(SUM,0,sizeof(SUM));
	int x,y ;
	for(int i = 1; i <= n ;i ++)
	{
       scanf("%d %d",&x,&y);
	   x++;
	   SUM[sum(x)]++;
	   update(x);
	}
	for(int i = 1;i <=  n ; i++)
	{
	  printf("%d\n",SUM[i-1]);
	}
return 0 ;
}
