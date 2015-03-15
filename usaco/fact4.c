// File Name: fact4.c
// Author: darkdream
// Created Time: 2014年02月26日 星期三 22时07分22秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
/*
ID: dream.y1
PROG: fact4
LANG: C++
*/
int hs[50000];
int t = 0 ; 
int a[40000];
void prime()
{
 memset(hs,0,sizeof(hs));
 int k = sqrt(4220);
 for(int i =2 ;i <= sqrt(4220+1) ;i ++)
 {
     if(!hs[i])
	 {
	   int t = i * i ; 
	   while(t <= 4220)
	   {
	     hs[t] =1 ; 
		 t += i ; 
	   }
	 }
 }
 for(int i = 2;i <= 4220 ;i ++ )
	 if(!hs[i])
	 {
	   t ++ ; 
	   a[t] = i ; 
	 }
}
int ans[40000];
int main(){
  freopen("fact4.in","r",stdin);
  freopen("fact4.out","w",stdout);
  int n; 
  memset(ans,0,sizeof(ans));
  scanf("%d",&n);
  prime();
  //printf("%d\n",t);
  for(int i = 1; i <= t ;i ++)
  {
	 int temp = n ; 
     while(temp >= a[i])
	 {
	   ans[i] += temp / a[i];
	   temp = temp / a[i];
	 }
		 
  }
  int sum = 1;
  ans[1] -= ans[3];
  ans[3] = 0 ; 
  for(int i = 1 ;i <= t;i ++)
  {
     while(ans[i])
	 {
	    sum = sum * a[i] % 10 ; 
	    ans[i] -- ; 
	 }
  }
  printf("%d\n",sum);
return 0 ;
}
