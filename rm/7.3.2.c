// File Name: 7.3.2.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 19时23分35秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int b[1000];
void print_subset(int n , int *B , int cur)
{
   if(cur == n)
   {
     for(int i = 0 ;i < n;i ++)
	   if(B[i])
		 printf("%d ",i);
	 printf("\n");
	 return;
   }
   B[cur] = 0 ;
   print_subset(n,B,cur+1);
   B[cur] = 1;
   print_subset(n,B,cur+1);
}
int main(){
  int n ;
  scanf("%d",&n);
 print_subset(n,b,0);

return 0 ;
}
